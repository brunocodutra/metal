# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8)

project(Metal CXX)

set(METAL_MAJOR_VERSION 0)
set(METAL_MINOR_VERSION 1)
set(METAL_PATCH_VERSION 0)
set(METAL_VERSION
    ${METAL_MAJOR_VERSION}.${METAL_MINOR_VERSION}.${METAL_PATCH_VERSION}
)

if(WIN32 AND NOT CYGWIN)
  set(METAL_CMAKE_INSTALL_DIR_DEF CMake)
else()
  set(METAL_CMAKE_INSTALL_DIR_DEF lib/cmake/Metal)
endif()

set(METAL_CMAKE_INSTALL_DIR
    ${METAL_CMAKE_INSTALL_DIR_DEF} CACHE PATH
    "installation directory for Metal CMake files"
)

set(METAL_INCLUDE_INSTALL_DIR
    include CACHE PATH
    "installation directory for Metal header files"
)

option(METAL_VERBOSE                "increase output verbosity"             OFF)
option(METAL_ENABLE_BASIC_WARNINGS  "enable basic compiler warnings"        OFF)
option(METAL_ENABLE_EXTRA_WARNINGS  "enable extra compiler warnings"        OFF)
option(METAL_STRICT                 "treat compiler warnings as errors"     OFF)

if(METAL_ENABLE_EXTRA_WARNINGS)
    set(METAL_ENABLE_BASIC_WARNINGS ON)
endif()

include(CheckCXXCompilerFlag)

function(metal_add_test_tree _tree)
    file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
    file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
    list(SORT sources)

    foreach(source ${sources})
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/src/" "" target ${source})
        string(REGEX REPLACE "[/\\]" "." target ${target})
        string(REGEX REPLACE "(.*)[.]cpp" "${_tree}.\\1" target ${target})

        add_executable(${target} EXCLUDE_FROM_ALL ${source} ${headers})
        add_test(${target} ${CMAKE_CURRENT_BINARY_DIR}/${target})

        string(REGEX REPLACE "(.*)[.][^.]+" "\\1" parent ${target})
        while(NOT TARGET ${parent})
            add_custom_target(${parent})
            add_dependencies(${parent} ${target})
            set(target ${parent})
            string(REGEX REPLACE "(.*)[.][^.]+" "\\1" parent ${target})
        endwhile()
        add_dependencies(${parent} ${target})
    endforeach()
endfunction()

macro(metal_add_flag _flag)
    set(result "${_flag}")
    string(TOUPPER "${result}" result)
    string(REGEX REPLACE "[+]" "X" result "${result}")
    string(REGEX REPLACE "[-/;=]" "_" result "${result}")
    string(REGEX REPLACE "[^ A-Z_0-9]" "" result "${result}")
    string(REGEX REPLACE "^[ ]*([A-Z_0-9]+) ?.*$" "\\1" result "${result}")
    set(result "HAS${result}")

    check_cxx_compiler_flag("${_flag} ${ARGN}" ${result})
    if(${result})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_flag}")
    endif()
endmacro()

if(METAL_VERBOSE)
    metal_add_flag(-v)
    metal_add_flag(-ftemplate-backtrace-limit=0)
    metal_add_flag(-fdiagnostics-show-template-tree)
    metal_add_flag(-fno-elide-type)
endif()

if(METAL_ENABLE_BASIC_WARNINGS)
    metal_add_flag(-W)
    metal_add_flag(-Wall)
    metal_add_flag(/W3)
endif()

if(METAL_ENABLE_EXTRA_WARNINGS)
    metal_add_flag(-Wextra)
    metal_add_flag(-Weverything)
    metal_add_flag(-Wno-c++98-compat)
    metal_add_flag(-Wno-c++98-compat-pedantic)
    metal_add_flag(-Wno-documentation-unknown-command)
    metal_add_flag(/W4)
endif()

if(METAL_STRICT)
    metal_add_flag(-pedantic-errors)
    metal_add_flag(-Werror)
    metal_add_flag(/WX)
endif()

metal_add_flag(-ftemplate-depth=512)

foreach(dialect
    -std=c++17 -std=c++1z
    -std=c++14 -std=c++1y
    -std=c++11 -std=c++0x
    /Za
)
    metal_add_flag(${dialect})
    if(${result})
        break()
    endif()
endforeach()

set(METAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
file(GLOB_RECURSE METAL_HEADERS "${METAL_INCLUDE_DIR}/*.hpp")

include_directories("${METAL_INCLUDE_DIR}")

enable_testing()

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)

foreach(x INCLUDE CMAKE)
  if(NOT IS_ABSOLUTE "${METAL_${x}_INSTALL_DIR}")
    set(METAL_${x}_INSTALL_DIR
        "${CMAKE_INSTALL_PREFIX}/${METAL_${x}_INSTALL_DIR}"
    )
  endif()
endforeach()

file(
    RELATIVE_PATH METAL_INCLUDE_DIRS_CONF
    "${METAL_CMAKE_INSTALL_DIR}" "${METAL_INCLUDE_INSTALL_DIR}"
)

set(METAL_INCLUDE_DIRS_CONF "\${METAL_CMAKE_DIR}/${METAL_INCLUDE_DIRS_CONF}")
configure_file(cmake/MetalConfig.cmake.in
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfig.cmake"
    @ONLY
)

configure_file(cmake/MetalConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfigVersion.cmake"
    @ONLY
)

install(DIRECTORY "${METAL_INCLUDE_DIR}"
    DESTINATION "${METAL_INCLUDE_INSTALL_DIR}"
)

install(FILES
  "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfig.cmake"
  "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfigVersion.cmake"
  DESTINATION "${METAL_CMAKE_INSTALL_DIR}"
)
