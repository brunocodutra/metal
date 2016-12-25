# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.0)

project(Metal CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Deploy)

set(METAL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")

file(STRINGS "${METAL_INCLUDE_DIR}/metal/config/version.hpp"
    METAL_CONFIG_VERSION_HPP REGEX "METAL_[A-Z]+ [0-9]+" LIMIT_COUNT 3
)

LIST(GET METAL_CONFIG_VERSION_HPP 0 METAL_MAJOR)
LIST(GET METAL_CONFIG_VERSION_HPP 1 METAL_MINOR)
LIST(GET METAL_CONFIG_VERSION_HPP 2 METAL_PATCH)

string(REGEX REPLACE ".*MAJOR ([0-9]+).*" "\\1" METAL_MAJOR "${METAL_MAJOR}")
string(REGEX REPLACE ".*MINOR ([0-9]+).*" "\\1" METAL_MINOR "${METAL_MINOR}")
string(REGEX REPLACE ".*PATCH ([0-9]+).*" "\\1" METAL_PATCH "${METAL_PATCH}")

set(METAL_VERSION "${METAL_MAJOR}.${METAL_MINOR}.${METAL_PATCH}")

message(STATUS "Configuring Metal ${METAL_VERSION}")

add_library(Metal INTERFACE)
set_target_properties(Metal PROPERTIES
    INTERFACE_LIB_VERSION ${METAL_VERSION}
    INTERFACE_INCLUDE_DIRECTORIES ${METAL_INCLUDE_DIR}
)

deploy(Metal)

include("${CMAKE_SOURCE_DIR}/cmake/config.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/testing.cmake")

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)
