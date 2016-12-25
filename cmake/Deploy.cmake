# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

function(deploy _pkg)
    get_target_property(name ${_pkg} NAME)
    get_target_property(version ${_pkg} INTERFACE_LIB_VERSION)
    get_target_property(include_dirs ${_pkg} INTERFACE_INCLUDE_DIRECTORIES)

    if(WIN32 AND NOT CYGWIN)
        set(cmake_install_dir CMake)
    else()
        set(cmake_install_dir lib/cmake/${CMAKE_PROJECT_NAME})
    endif()

    set(include_install_dir include)

    file(RELATIVE_PATH relative_include_install_dir
        /${cmake_install_dir} /${include_install_dir}
    )

    set(config_file "${CMAKE_CURRENT_BINARY_DIR}/${name}Config.cmake")
    set(version_file "${CMAKE_CURRENT_BINARY_DIR}/${name}ConfigVersion.cmake")

    file(WRITE ${config_file} "\
# ${name} configuration file
#
# Defines:
#   ${name}_INCLUDE_DIR - ${name} include directory

set(${name}_INCLUDE_DIR \"\${CMAKE_CURRENT_LIST_DIR}/${relative_include_install_dir}\")
"
    )

    file(WRITE ${version_file} "\
# ${name} version file

set(PACKAGE_VERSION ${version})

if(PACKAGE_VERSION VERSION_LESS PACKAGE_FIND_VERSION)
    set(PACKAGE_VERSION_COMPATIBLE FALSE)
else()
    set(PACKAGE_VERSION_COMPATIBLE TRUE)
    if(PACKAGE_VERSION VERSION_EQUAL PACKAGE_FIND_VERSION)
        set(PACKAGE_VERSION_EXACT TRUE)
    endif()
endif()
"
    )

    foreach(dir ${include_dirs})
        install(DIRECTORY ${dir} DESTINATION ${include_install_dir})
    endforeach()

    install(FILES ${config_file} ${version_file}
        DESTINATION ${cmake_install_dir}
    )
endfunction()
