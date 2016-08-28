# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 2.8.12)

project(Metal CXX)

include("${CMAKE_SOURCE_DIR}/cmake/config.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/testing.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/deployment.cmake")

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)
