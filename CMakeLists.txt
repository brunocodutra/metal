# This file is part of mpl2, a free software.
# Use, modification and distribution is subject to the BSD 2-clause license.
# See accompanying file LICENSE for its full text.

cmake_minimum_required(VERSION 2.8.3)

option(BUILD_TESTS "build test scripts" ON)

project(mpl2 CXX)

find_package(Boost 1.57 REQUIRED)

set(BOOST_MPL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BOOST_MPL2_INCLUDE_DIRS ${BOOST_MPL2_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

file(GLOB_RECURSE BOOST_MPL2_HEADERS ${BOOST_MPL2_INCLUDE_DIR}/*.hpp)

add_custom_target(mpl2 SOURCES ${BOOST_MPL2_HEADERS})
install(FILES ${BOOST_MPL2_HEADERS} DESTINATION include)

if(BUILD_TESTS)
    add_subdirectory(test EXCLUDE_FROM_ALL)
endif()

