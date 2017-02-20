# Copyright Bruno Dutra 2015-2017
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

include(ExternalProject)
function(test_deployment _target _pkg _header)
    get_target_property(name ${_pkg} NAME)
    get_target_property(version ${_pkg} INTERFACE_LIB_VERSION)

    set(prefix "${CMAKE_CURRENT_BINARY_DIR}/external")
    set(src_dir "${prefix}/src/${_target}")
    set(bin_dir "${src_dir}-build")

    file(WRITE "${src_dir}/CMakeLists.txt" "\
cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(external CXX)
find_package(${name} ${version} EXACT REQUIRED)
include_directories(\${${name}_INCLUDE_DIR})
add_executable(external main.cpp)
"
    )

    file(WRITE "${src_dir}/main.cpp"
        "#include <${_header}>\nint main(){return 0;}\n"
    )

    ExternalProject_Add(${_target}
        URL ""
        BUILD_ALWAYS 1
        EXCLUDE_FROM_ALL 1
        PREFIX ${prefix}
        CMAKE_GENERATOR ${CMAKE_GENERATOR}
        CMAKE_ARGS
            -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
            -DCMAKE_CXX_STANDARD=14
            -DCMAKE_PREFIX_PATH=${CMAKE_CURRENT_BINARY_DIR}/install
        INSTALL_COMMAND ""
    )

    ExternalProject_Add_Step(${_target} deploy
        ALWAYS 1
        EXCLUDE_FROM_ALL 1
        DEPENDERS configure
        COMMAND ${CMAKE_COMMAND} -E remove_directory install
        COMMAND ${CMAKE_COMMAND}
            -DCMAKE_INSTALL_PREFIX=install
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
endfunction()
