# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.1)

project(external CXX)

set(FIND_PACKAGE_ARGS REQUIRED)
if(METAL_VERSION)
    if(METAL_VERSION_EXACT)
        set(FIND_PACKAGE_ARGS EXACT ${FIND_PACKAGE_ARGS})
    endif()
    set(FIND_PACKAGE_ARGS ${METAL_VERSION} ${FIND_PACKAGE_ARGS})
endif()

find_package(Metal ${FIND_PACKAGE_ARGS})
include_directories(${METAL_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(external external.cpp)
