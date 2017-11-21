# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
    message(WARNING "doxygen not found - target 'doc' will be unavailable.")
    return()
endif()

configure_file(Doxyfile.in Doxyfile @ONLY)

set(output "${CMAKE_CURRENT_BINARY_DIR}/html/")

add_custom_command(
    OUTPUT ${output}
    COMMENT "generating docs..."
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${output}
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
    COMMAND ${CMAKE_COMMAND} -E remove
        "${output}/*.png" "${output}/dynsections.js" "${output}/doxygen.css"
        "${output}/tabs.css" "${output}/dir_*.html" "${output}/namespacemetal.html"
        "${output}/modules.html" "${output}/namespacemembers_type.html"
)

add_custom_target(doc DEPENDS ${output})
set_target_properties(doc PROPERTIES OUTPUT ${output})

deploy_doc(Metal doc)
