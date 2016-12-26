# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

macro(absolute _path)
    if(NOT IS_ABSOLUTE ${${_path}})
        set(${_path} "${CMAKE_CURRENT_SOURCE_DIR}/${${_path}}")
    endif()
endmacro()

function(assert_dir _path)
    if(NOT IS_DIRECTORY ${_path})
        message(FATAL_ERROR "'${_path}' is not a valid directory.")
    endif()
endfunction()

function(assert_target _target)
    if(NOT TARGET ${_target})
        message(FATAL_ERROR "'${_target}' is not a target.")
    endif()
endfunction()

function(test_build_and_run _target)
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
    )
endfunction()

function(get_tree_nodes _prefix _nodes)
    absolute(_prefix)
    assert_dir(${_prefix})

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

function(unit_test_tree _lib _root _prefix)
    absolute(_prefix)
    assert_dir(${_prefix})
    assert_target(${_root})

    get_tree_nodes(${_prefix} nodes)
    foreach(node ${nodes})
        set(target ${_root}.${node})
        set(node "${_prefix}/${node}")
        if(EXISTS "${node}.cpp")
            add_executable(${target} EXCLUDE_FROM_ALL "${node}.cpp")
            target_link_libraries(${target} ${_lib})
        elseif(IS_DIRECTORY ${node})
            add_custom_target(${target})
        endif()

        if(IS_DIRECTORY ${node})
            unit_test_tree(${_lib} ${target} ${node})
        endif()

        if(TARGET ${target})
            add_dependencies(${_root} ${target})
            test_build_and_run(${target})
        endif()
    endforeach()
endfunction()

function(header_test_tree _lib _root _prefix)
    absolute(_prefix)
    assert_dir(${_prefix})
    assert_target(${_root})

    get_tree_nodes(${_prefix} nodes)
    foreach(node ${nodes})
        set(target ${_root}.${node})
        set(node "${_prefix}/${node}")
        if(EXISTS "${node}.hpp")
            set(src "${CMAKE_CURRENT_BINARY_DIR}/${target}.cpp")
            file(WRITE ${src} "#include \"${node}.hpp\"\nint main(){return 0;}\n")
            add_executable(${target} EXCLUDE_FROM_ALL ${src})
            target_link_libraries(${target} ${_lib})
        elseif(IS_DIRECTORY ${node})
            add_custom_target(${target})
        endif()

        if(IS_DIRECTORY ${node})
            header_test_tree(${_lib} ${target} ${node})
        endif()

        if(TARGET ${target})
            add_dependencies(${_root} ${target})
            test_build_and_run(${target})
        endif()
    endforeach()
endfunction()
