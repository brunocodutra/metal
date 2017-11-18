# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.8)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
endif()

project(Metal CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Configure)
include(Deploy)
include(Test)

set(METAL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")

file(STRINGS "${METAL_INCLUDE_DIR}/metal/config/version.hpp"
    METAL_CONFIG_VERSION_HPP REGEX "METAL_[A-Z]+ [0-9]+" LIMIT_COUNT 3
)

list(GET METAL_CONFIG_VERSION_HPP 0 METAL_MAJOR)
list(GET METAL_CONFIG_VERSION_HPP 1 METAL_MINOR)
list(GET METAL_CONFIG_VERSION_HPP 2 METAL_PATCH)

string(REGEX REPLACE ".*MAJOR ([0-9]+).*" "\\1" METAL_MAJOR "${METAL_MAJOR}")
string(REGEX REPLACE ".*MINOR ([0-9]+).*" "\\1" METAL_MINOR "${METAL_MINOR}")
string(REGEX REPLACE ".*PATCH ([0-9]+).*" "\\1" METAL_PATCH "${METAL_PATCH}")

set(METAL_VERSION "${METAL_MAJOR}.${METAL_MINOR}.${METAL_PATCH}")

message(STATUS "Configuring Metal ${METAL_VERSION}")

add_header_library(Metal "${METAL_INCLUDE_DIR}/metal.hpp")
set_target_properties(Metal PROPERTIES
    INTERFACE_LIB_VERSION ${METAL_VERSION}
    INTERFACE_COMPILE_FEATURES cxx_std_11
)

deploy_header_library(Metal)

target_compile_flags(Metal INTERFACE -stdlib=libc++ LIBS c++ c++abi)

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)
