# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8.3)

project(Boost.MPL2 CXX)

find_package(Boost 1.57 REQUIRED)

set(BOOST_MPL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BOOST_MPL2_INCLUDE_DIRS ${BOOST_MPL2_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

file(GLOB_RECURSE BOOST_MPL2_HEADERS ${BOOST_MPL2_INCLUDE_DIR}/*.hpp)

add_custom_target(mpl2 SOURCES ${BOOST_MPL2_HEADERS})
install(FILES ${BOOST_MPL2_HEADERS} DESTINATION include)

option(BOOST_MPL2_BUILD_TESTS "build test scripts" ON)
if(BOOST_MPL2_BUILD_TESTS)
    add_subdirectory(test EXCLUDE_FROM_ALL)
endif()

