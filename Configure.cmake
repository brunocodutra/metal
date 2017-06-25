# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

include(CheckCXXCompilerFlag)

function(target_compile_flags _target _visibility _flag)
    set(options)
    set(one_value_args)
    set(multi_value_args FALLBACK LIBS CONFIGS)
    cmake_parse_arguments(ARGS "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    set(flags ${_flag} ${ARGS_FALLBACK})

    if(NOT ARGS_CONFIGS)
        set(ARGS_CONFIGS Debug Release RelWithDebInfo MinSizeRel)
    endif()

    foreach(flag ${flags})
        set(result "${flag}")
        string(REGEX REPLACE "[ ]" "" result "${result}")
        string(REGEX REPLACE "[+]" "x" result "${result}")
        string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" result "${result}")
        set(result "has${result}")

        set(CMAKE_REQUIRED_LIBRARIES ${ARGS_LIBS})
        check_cxx_compiler_flag(${flag} ${result})
        if(${result})
            foreach(config ${ARGS_CONFIGS})
                target_compile_options(${_target} ${_visibility} $<BUILD_INTERFACE:$<$<CONFIG:${config}>:${flag}>>)
                target_link_libraries(${_target} ${_visibility} $<BUILD_INTERFACE:$<$<CONFIG:${config}>:${ARGS_LIBS}>>)
            endforeach()
            break()
        endif()
    endforeach()
endfunction()
