# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

find_package(Boost)

set(exclude)
if(NOT Boost_FOUND OR Boost_MINOR_VERSION LESS 61)
    list(APPEND exclude "sfinae")
    message(WARNING "boost not found - target 'example.sfinae' will be unavailable.")
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()

test_units(example Metal "${CMAKE_CURRENT_SOURCE_DIR}/src/" EXCLUDE ${exclude})

add_custom_target(examples DEPENDS example)
