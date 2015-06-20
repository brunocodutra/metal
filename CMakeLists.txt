# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8.3)

project(Metal CXX)

set(BOOST_METAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BOOST_METAL_INCLUDE_DIRS ${BOOST_METAL_INCLUDE_DIR})

file(GLOB_RECURSE BOOST_METAL_HEADERS ${BOOST_METAL_INCLUDE_DIR}/*.hpp)

add_custom_target(metal SOURCES ${BOOST_METAL_HEADERS})
install(FILES ${BOOST_METAL_HEADERS} DESTINATION include)

option(BOOST_METAL_BUILD_TEST "build test" ON)
if(BOOST_METAL_BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()

option(BOOST_METAL_BUILD_DOC "build documentation" OFF)
if(BOOST_METAL_BUILD_DOC)
    add_subdirectory(doc)
endif()


