cmake_minimum_required(VERSION 3.8)

include(cmake/Deploy.cmake)
include(cmake/Test.cmake)

project(Metal CXX)

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

add_header_library(Metal "${METAL_INCLUDE_DIR}/metal.hpp" "LICENSE")
set_target_properties(Metal PROPERTIES
    INTERFACE_LIB_VERSION ${METAL_VERSION}
    INTERFACE_COMPILE_FEATURES cxx_std_11
)

deploy_header_library(Metal)

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)
