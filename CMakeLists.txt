# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8.3)

project(Metal CXX)

set(METAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(METAL_INCLUDE_DIRS ${METAL_INCLUDE_DIR})

file(GLOB_RECURSE METAL_HEADERS ${METAL_INCLUDE_DIR}/*.hpp)

add_custom_target(metal SOURCES ${METAL_HEADERS})
install(FILES ${METAL_HEADERS} DESTINATION include)

option(METAL_BUILD_TEST "build test" ON)
if(METAL_BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()

option(METAL_BUILD_DOC "build documentation" OFF)
if(METAL_BUILD_DOC)
    add_subdirectory(doc)
endif()


