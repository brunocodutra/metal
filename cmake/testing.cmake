# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

enable_testing()

function(metal_build_test_tree _root _prefix)
    if(NOT TARGET ${_root})
        message(FATAL_ERROR "'${_root}' is not a target.")
    endif()

    if(NOT IS_ABSOLUTE "${_prefix}")
        set(_prefix "${CMAKE_CURRENT_SOURCE_DIR}/${_prefix}")
    endif()

    if(NOT IS_DIRECTORY "${_prefix}")
        message(FATAL_ERROR "'${_prefix}' is not a valid directory.")
    endif()

    set(nodes)
    file(GLOB files ${_prefix}/*)
    list(SORT files)
    foreach(file ${files})
        get_filename_component(node "${file}" NAME_WE)
        list(APPEND nodes ${node})
    endforeach()
    list(REMOVE_DUPLICATES nodes)

    foreach(node ${nodes})
        set(target ${_root}.${node})
        if(EXISTS "${_prefix}/${node}.cpp")
            add_executable(${target} EXCLUDE_FROM_ALL "${_prefix}/${node}.cpp")
            target_link_libraries(${target} metal)
        else()
            add_custom_target(${target})
        endif()
        add_dependencies(${_root} ${target})

        if(IS_DIRECTORY "${_prefix}/${node}")
            metal_build_test_tree(${target} "${_prefix}/${node}")
        endif()

        add_test(NAME ${target}
            COMMAND ${CMAKE_COMMAND} --build . --target ${target}
            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
        )
    endforeach()
endfunction()
