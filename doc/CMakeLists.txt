# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
    message(WARNING "doxygen not found - target 'doc' will be unavailable.")
    return()
endif()

configure_file(Doxyfile.in Doxyfile @ONLY)

add_custom_target(doc
    COMMAND ${CMAKE_COMMAND} -E remove_directory "html"
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
    COMMAND ${CMAKE_COMMAND} -E remove
        "html/*.png" "html/dynsections.js" "html/doxygen.css" "html/tabs.css"
        "html/dir_*.html" "html/namespacemetal.html" "html/modules.html"
        "html/namespacemembers_type.html"
)

set_target_properties(doc PROPERTIES OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/html/")

deploy_doc(Metal doc)
