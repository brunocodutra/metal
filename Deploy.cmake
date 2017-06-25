# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

set(THIS_FILE ${CMAKE_CURRENT_LIST_FILE})

function(singlify _entry _output)
    set(options)
    set(one_value_args EXCLUDED)
    set(multi_value_args EXCLUDE INCLUDE_DIRS)
    cmake_parse_arguments(ARGS "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    if(NOT IS_ABSOLUTE ${_entry})
        set(_entry "${CMAKE_CURRENT_SOURCE_DIR}/${_entry}")
    endif()

    set(exclude)
    if(ARGS_EXCLUDE)
        set(exclude ${ARGS_EXCLUDE})
    endif()

    get_filename_component(include_dirs ${_entry} DIRECTORY)
    if(ARGS_INCLUDE_DIRS)
        foreach(dir ${ARGS_INCLUDE_DIRS})
            if(NOT IS_ABSOLUTE ${dir})
                set(dir "${CMAKE_CURRENT_SOURCE_DIR}/${dir}")
            endif()
            list(APPEND include_dirs ${dir})
        endforeach()
    endif()

    set(output "${${_output}}")
    file(STRINGS ${_entry} lines NEWLINE_CONSUME)
    string(REGEX REPLACE "[\\][\n][ \t]*" "" lines "${lines}")
    string(REGEX REPLACE "\n" ";" lines "${lines}")
    foreach(line ${lines})
        set(next false)
        set(regex "^[ \t]*#[ \t]*include[ \t]*[\"<]([^\">]*)[\">]")
        if(line MATCHES ${regex})
            string(REGEX REPLACE ${regex} "\\1" include "${line}")
            foreach(dir ${include_dirs})
                if(EXISTS "${dir}/${include}")
                    set(next "${dir}/${include}")
                    get_filename_component(next "${next}" ABSOLUTE)
                    break()
                endif()
            endforeach()
        endif()

        if(next)
            if(NOT next IN_LIST exclude)
                list(APPEND exclude ${next})
                singlify(${next} output
                    EXCLUDE ${exclude}
                    EXCLUDED exclude
                    INCLUDE_DIRS ${ARGS_INCLUDE_DIRS}
                )
            endif()
        else()
            set(output "${output}${line}\n")
        endif()
    endforeach()

    if(ARGS_EXCLUDED)
        set(${ARGS_EXCLUDED} ${exclude} PARENT_SCOPE)
    endif()

    set(${_output} "${output}" PARENT_SCOPE)
endfunction()

function(add_header_library _name _entry)
    get_filename_component(output ${_entry} NAME)
    set(output_dir "${CMAKE_BINARY_DIR}/singlified/${_name}")
    set(output "${output_dir}/${output}")

    get_filename_component(include_dir ${_entry} DIRECTORY)
    file(GLOB_RECURSE headers "${include_dir}/*.hpp")

    set(singlify_cmake "${CMAKE_BINARY_DIR}/${_name}.singlify.cmake")
    file(WRITE ${singlify_cmake} "\
cmake_minimum_required(VERSION ${CMAKE_VERSION})
include(${THIS_FILE})
singlify(${_entry} single INCLUDE_DIRS ${include_dir})
file(WRITE \"${output}\" \"\${single}\")
"
    )

    add_custom_command(OUTPUT ${output}
        COMMAND ${CMAKE_COMMAND} -P ${singlify_cmake}
        COMMENT "singlifying ${_name}..."
        DEPENDS ${headers}
    )

    add_custom_target(${_name}.singlify DEPENDS ${output} SOURCES ${headers})

    add_library(${_name} INTERFACE)
    target_include_directories(${_name} INTERFACE $<BUILD_INTERFACE:${output_dir}>)

    add_dependencies(${_name} ${_name}.singlify)
endfunction()

include(CMakePackageConfigHelpers)

function(deploy_header_library _lib)
    get_target_property(name ${_lib} NAME)
    get_target_property(version ${_lib} INTERFACE_LIB_VERSION)
    get_target_property(features ${_lib} INTERFACE_COMPILE_FEATURES)
    get_target_property(include_dirs ${_lib} INTERFACE_INCLUDE_DIRECTORIES)

    target_include_directories(${_lib} INTERFACE $<INSTALL_INTERFACE:include>)

    if(WIN32 AND NOT CYGWIN)
        set(cmake_install_dir CMake)
        set(include_install_dir "${name}/include")
    else()
        set(cmake_install_dir "share/cmake/${name}")
        set(include_install_dir include)
    endif()

    set(config_file "${CMAKE_BINARY_DIR}/${name}Config.cmake")
    set(version_file "${CMAKE_BINARY_DIR}/${name}ConfigVersion.cmake")

    file(WRITE ${config_file} "\
get_filename_component(${name}_CMAKE_DIR \"\${CMAKE_CURRENT_LIST_FILE}\" PATH)
include(\"\${${name}_CMAKE_DIR}/${name}Targets.cmake\")
"
    )

    write_basic_package_version_file(${version_file}
        VERSION ${version}
        COMPATIBILITY AnyNewerVersion
    )

    install(TARGETS ${_lib} EXPORT ${name}Targets)
    install(EXPORT ${name}Targets DESTINATION ${cmake_install_dir})
    install(FILES ${config_file} ${version_file} DESTINATION ${cmake_install_dir})

    foreach(dir ${include_dirs})
        install(DIRECTORY ${dir}/ DESTINATION ${include_install_dir})
    endforeach()

    if(NOT TARGET deploy)
        add_custom_target(deploy ALL)
    endif()

    add_dependencies(deploy ${_lib})
endfunction()

function(deploy_doc _lib _doc)
    get_target_property(name ${_lib} NAME)
    get_target_property(doc ${_doc} OUTPUT)

    if(WIN32 AND NOT CYGWIN)
        set(doc_install_dir "${name}/doc")
    else()
        set(doc_install_dir "share/${name}/doc")
    endif()

    set(dist "${PROJECT_BINARY_DIR}/dist/")
    set(dist_doc "${dist}/${doc_install_dir}/")

    add_custom_target(${_doc}.deploy
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${dist_doc}
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${doc} ${dist_doc}
        COMMENT "deploying ${name} docs..."
        DEPENDS ${_doc}
    )

    install(DIRECTORY ${dist} DESTINATION .)

    if(NOT TARGET deploy)
        add_custom_target(deploy)
    endif()

    add_dependencies(deploy ${_doc}.deploy)
endfunction()
