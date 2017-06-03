# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

enable_testing()

function(test _target)
    get_target_property(target_type ${_target} TYPE)
    if(target_type STREQUAL "EXECUTABLE")
        add_custom_target(${_target}.driver
            COMMAND ${CMAKE_COMMAND} --build . --target ${_target} --config ${CMAKE_BUILD_TYPE}
            COMMAND "$<TARGET_FILE:${_target}>"
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        )
    else()
        add_custom_target(${_target}.driver
            COMMAND ${CMAKE_COMMAND} --build . --target ${_target} --config ${CMAKE_BUILD_TYPE}
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
        )
    endif()
    add_test(NAME ${_target}
        COMMAND ${CMAKE_COMMAND} --build . --target ${_target}.driver
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    )
endfunction()

function(get_tree_nodes _prefix _nodes)
    set(nodes)
    file(GLOB files ${_prefix}/*)
    list(SORT files)
    foreach(file ${files})
        get_filename_component(node ${file} NAME_WE)
        list(APPEND nodes ${node})
    endforeach()
    list(REMOVE_DUPLICATES nodes)
    set(${_nodes} ${nodes} PARENT_SCOPE)
endfunction()

function(test_units _root _lib _prefix)
    set(options)
    set(one_value_args)
    set(multi_value_args EXCLUDE)
    cmake_parse_arguments(ARGS "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    if(NOT ARGS_EXCLUDE)
        set(ARGS_EXCLUDE "^$")
    else()
        string(REPLACE ";" "|" ARGS_EXCLUDE "${ARGS_EXCLUDE}")
    endif()

    if(NOT IS_ABSOLUTE ${_prefix})
        set(_prefix "${CMAKE_CURRENT_SOURCE_DIR}/${_prefix}")
    endif()

    if(NOT IS_DIRECTORY ${_prefix} OR NOT EXISTS ${_prefix})
        message(FATAL_ERROR "'${_prefix}' is not a valid directory.")
    endif()

    if(NOT TARGET ${_root})
        add_custom_target(${_root})
    endif()

    get_tree_nodes(${_prefix} nodes)
    foreach(node ${nodes})
        if(node MATCHES ${ARGS_EXCLUDE})
            continue()
        endif()

        set(target ${_root}.${node})
        set(node "${_prefix}/${node}")
        if(EXISTS "${node}.cpp")
            add_executable(${target} EXCLUDE_FROM_ALL "${node}.cpp")
            target_link_libraries(${target} ${_lib})
        endif()

        if(IS_DIRECTORY ${node})
            test_units(${target} ${_lib} ${node} ${ARGN})
        endif()

        if(TARGET ${target})
            add_dependencies(${_root} ${target})
            test(${target})
        endif()
    endforeach()
endfunction()

function(test_headers _root _lib _prefix)
    set(options)
    set(one_value_args)
    set(multi_value_args EXCLUDE)
    cmake_parse_arguments(ARGS "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    if(NOT ARGS_EXCLUDE)
        set(ARGS_EXCLUDE "^$")
    else()
        string(REPLACE ";" "|" ARGS_EXCLUDE "${ARGS_EXCLUDE}")
    endif()

    if(NOT IS_ABSOLUTE ${_prefix})
        set(_prefix "${CMAKE_CURRENT_SOURCE_DIR}/${_prefix}")
    endif()

    if(NOT IS_DIRECTORY ${_prefix} OR NOT EXISTS ${_prefix})
        message(FATAL_ERROR "'${_prefix}' is not a valid directory.")
    endif()

    if(NOT TARGET ${_root})
        add_custom_target(${_root})
    endif()

    get_tree_nodes(${_prefix} nodes)
    foreach(node ${nodes})
        if(node MATCHES ${ARGS_EXCLUDE})
            continue()
        endif()

        set(target ${_root}.${node})
        set(node "${_prefix}/${node}")
        if(EXISTS "${node}.hpp")
            set(src "${CMAKE_CURRENT_BINARY_DIR}/${target}.cpp")
            file(WRITE ${src} "#include \"${node}.hpp\"\nint main(){return 0;}\n")
            add_executable(${target} EXCLUDE_FROM_ALL ${src})
            target_link_libraries(${target} ${_lib})
        endif()

        if(IS_DIRECTORY ${node})
            test_headers(${target} ${_lib} ${node} ${ARGN})
        endif()

        if(TARGET ${target})
            add_dependencies(${_root} ${target})
            test(${target})
        endif()
    endforeach()
endfunction()
