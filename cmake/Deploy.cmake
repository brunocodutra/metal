set(THIS_FILE ${CMAKE_CURRENT_LIST_FILE})

function(copyright _license _output)
    set(output "${${_output}}")
    file(STRINGS ${_license} lines NEWLINE_CONSUME)
    string(REGEX REPLACE "\n$" "" lines "${lines}")
    string(REGEX REPLACE "\n" "\n// " output "// ${lines}")
    set(${_output} "${output}\n\n" PARENT_SCOPE)
endfunction()

function(bundle _entry _output)
    set(options)
    set(one_value_args EXCLUDED)
    set(multi_value_args EXCLUDE)
    cmake_parse_arguments(ARGS "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

    set(exclude)
    if(ARGS_EXCLUDE)
        set(exclude ${ARGS_EXCLUDE})
    endif()

    get_filename_component(include_dir ${_entry} DIRECTORY)

    set(output "${${_output}}")
    file(STRINGS ${_entry} lines NEWLINE_CONSUME)
    string(REGEX REPLACE "[\\][\n][ \t]*" "" lines "${lines}")
    string(REGEX REPLACE "\n" ";" lines "${lines}")
    foreach(line ${lines})
        set(next false)
        set(regex "^[ \t]*#[ \t]*include[ \t]*[\"<]([^\">]*)[\">]")
        if(line MATCHES ${regex})
            string(REGEX REPLACE ${regex} "\\1" include "${line}")
            if(NOT IS_ABSOLUTE "${include}" AND EXISTS "${include_dir}/${include}")
                set(next "${include_dir}/${include}")
                get_filename_component(next "${next}" ABSOLUTE)
            endif()
        endif()

        if(next)
            if(NOT next IN_LIST exclude)
                list(APPEND exclude ${next})
                bundle(${next} output EXCLUDE ${exclude} EXCLUDED exclude)
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

function(add_header_library _name _entry _license)
    if(NOT IS_ABSOLUTE ${_entry})
        set(_entry "${CMAKE_CURRENT_SOURCE_DIR}/${_entry}")
    endif()

    if(NOT IS_ABSOLUTE ${_license})
        set(_license "${CMAKE_CURRENT_SOURCE_DIR}/${_license}")
    endif()

    get_filename_component(output ${_entry} NAME)
    set(output_dir "${CMAKE_BINARY_DIR}/${_name}/include")
    set(output "${output_dir}/${output}")

    get_filename_component(include_dir ${_entry} DIRECTORY)
    file(GLOB_RECURSE headers "${include_dir}/*.hpp")

    set(bundle "${CMAKE_BINARY_DIR}/${_name}/bundle.cmake")
    file(WRITE ${bundle} "\
cmake_minimum_required(VERSION ${CMAKE_VERSION})
include(${THIS_FILE})
copyright(${_license} output)
bundle(${_entry} output)
file(WRITE \"${output}\" \"\${output}\")
"
    )

    add_custom_command(
        OUTPUT ${output}
        COMMAND ${CMAKE_COMMAND} -P ${bundle}
        COMMENT "bundling ${_name}..."
        DEPENDS ${headers}
    )

    add_custom_target(${_name}.bundle DEPENDS ${output} SOURCES ${headers})

    add_library(${_name} INTERFACE)
    target_include_directories(${_name} INTERFACE $<BUILD_INTERFACE:${output_dir}>)

    if (NOT TARGET bundle)
        add_custom_target(bundle ALL)
    endif()

    add_dependencies(bundle ${_name}.bundle)
    add_dependencies(${_name} ${_name}.bundle)
endfunction()

include(CMakePackageConfigHelpers)

function(deploy_header_library _lib)
    get_target_property(name ${_lib} NAME)
    get_target_property(version ${_lib} INTERFACE_LIB_VERSION)
    get_target_property(dirs ${_lib} INTERFACE_INCLUDE_DIRECTORIES)

    set(include_dest "include")
    set(cmake_dest "lib/cmake/${name}")
    set(cmake_src "${CMAKE_BINARY_DIR}/${name}/${cmake_dest}")

    set(config_file "${cmake_src}/${name}Config.cmake")
    set(version_file "${cmake_src}/${name}ConfigVersion.cmake")
    set(targets_file "${cmake_src}/${name}Targets.cmake")

    file(WRITE ${config_file} "include(\${CMAKE_CURRENT_LIST_DIR}/${name}Targets.cmake)")

    write_basic_package_version_file(${version_file}
        VERSION ${version}
        COMPATIBILITY SameMajorVersion
    )

    install(FILES ${config_file} ${version_file} DESTINATION ${cmake_dest})
    install(TARGETS ${_lib} EXPORT ${name}Targets INCLUDES DESTINATION ${include_dest})
    install(EXPORT ${name}Targets DESTINATION ${cmake_dest})
    export(TARGETS ${_lib} FILE ${targets_file})

    foreach(dir ${dirs})
        install(DIRECTORY ${dir}/ DESTINATION ${include_dest})
    endforeach()
endfunction()

function(deploy_doc _lib _doc)
    get_target_property(name ${_lib} NAME)
    get_target_property(dir ${_doc} OUTPUT)

    if(WIN32 AND NOT CYGWIN)
        set(install_dir "${name}/doc")
    else()
        set(install_dir "share/${name}/doc")
    endif()

    install(DIRECTORY ${dir}/ DESTINATION ${install_dir} OPTIONAL)
endfunction()
