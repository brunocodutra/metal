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

find_program(CLANG_FORMAT NAMES clang-format)
function(test_formatting _root _lib _prefix)
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
        set(formatted "${CMAKE_CURRENT_BINARY_DIR}/${target}.hpp")
        set(node "${_prefix}/${node}")
        set(original "${node}.hpp")
        if(EXISTS ${original})
            file(RELATIVE_PATH comment ${PROJECT_SOURCE_DIR} ${original})
            set(comment "checking whether '${comment}' is well formatted...")

            add_custom_target(${target}
                COMMAND ${CLANG_FORMAT} ${original} > ${formatted}
                COMMAND ${CMAKE_COMMAND} -E compare_files ${original} ${formatted}
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                COMMENT ${comment}
            )
        endif()

        if(IS_DIRECTORY ${node})
            test_formatting(${target} ${_lib} ${node} ${ARGN})
        endif()

        if(TARGET ${target})
            add_dependencies(${_root} ${target})
            test(${target})
        endif()
    endforeach()
endfunction()

include(ExternalProject)
function(test_deployment _target _lib _version _entry)
    set(prefix "${CMAKE_CURRENT_BINARY_DIR}/dependent")
    set(src_dir "${prefix}/src/${_target}")
    set(bin_dir "${src_dir}-build")

    file(WRITE "${src_dir}/CMakeLists.txt" "\
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(dependent CXX)
find_package(${_lib} ${_version} EXACT REQUIRED)
add_executable(dependent main.cpp)
target_link_libraries(dependent ${_lib})
"
    )

    file(WRITE "${src_dir}/main.cpp"
        "#include <${_entry}>\nint main(){return 0;}\n"
    )

    ExternalProject_Add(${_target}
        URL ""
        BUILD_ALWAYS 1
        EXCLUDE_FROM_ALL 1
        PREFIX ${prefix}
        CMAKE_GENERATOR ${CMAKE_GENERATOR}
        CMAKE_ARGS
            -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
            -DCMAKE_PREFIX_PATH=${CMAKE_CURRENT_BINARY_DIR}/fakeroot
        INSTALL_COMMAND ""
    )

    ExternalProject_Add_Step(${_target} deploy
        ALWAYS 1
        EXCLUDE_FROM_ALL 1
        DEPENDERS configure
        COMMAND ${CMAKE_COMMAND} -E remove_directory fakeroot
        COMMAND ${CMAKE_COMMAND}
            -DCMAKE_INSTALL_PREFIX=fakeroot
            -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

    ExternalProject_Add_Step(${_target} clean
        ALWAYS 1
        EXCLUDE_FROM_ALL 1
        DEPENDEES configure
        COMMAND ${CMAKE_COMMAND} --build ${bin_dir} --target clean
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

    test(${_target})
endfunction()
