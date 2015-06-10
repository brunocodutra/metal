# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

find_package(Doxygen)
if (NOT DOXYGEN_FOUND)
    message(WARNING "doxygen not found - 'doc' target will be unavailable.")
    return()
endif()

configure_file(Doxyfile.in BOOST_METAL_DOXYFILE @ONLY)
add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} BOOST_METAL_DOXYFILE
    COMMENT "doxygenating..."
)