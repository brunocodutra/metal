# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

if(NOT DOXYGEN_FOUND)
    message(
        WARNING
        "doxygen not found - 'metal.doc' target will be unavailable."
    )
    return()
endif()

configure_file(Doxyfile.in METAL_DOXYFILE @ONLY)
add_custom_target(
    metal.doc
    COMMAND ${CMAKE_COMMAND} -E remove_directory html
    COMMAND ${DOXYGEN_EXECUTABLE} METAL_DOXYFILE
    COMMENT "doxygenating..."
)
add_custom_target(doc DEPENDS metal.doc)

add_dependencies(metal metal.doc)

if(NOT GIT_FOUND)
    message(
        WARNING
        "git not found - 'metal.doc.update' target will be unavailable."
    )
    return()
endif()

if(DEFINED ENV{GITHUB_TOKEN})
    set(
        METAL_ORIGIN_URL
        "https://brunocodutra:$ENV{GITHUB_TOKEN}@github.com/brunocodutra/metal"
    )
else()
    set(
        METAL_ORIGIN_URL
        "https://github.com/brunocodutra/metal"
    )
endif()

execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
    OUTPUT_VARIABLE METAL_CURRENT_REVISION
    OUTPUT_STRIP_TRAILING_WHITESPACE
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    metal.doc.update
    COMMAND ${CMAKE_COMMAND} -E remove_directory gh-pages
    COMMAND ${GIT_EXECUTABLE} clone ${METAL_ORIGIN_URL} --depth 1 --branch=gh-pages gh-pages
    COMMAND ${CMAKE_COMMAND} -E copy_directory gh-pages/.git html/.git
    COMMAND ${CMAKE_COMMAND} -E remove_directory gh-pages
    COMMAND ${GIT_EXECUTABLE} -C html add --all .
    COMMAND ${GIT_EXECUTABLE} -C html commit --allow-empty -m "updating to ${METAL_CURRENT_REVISION}"
    COMMAND ${GIT_EXECUTABLE} -C html push origin gh-pages
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "updating online documentation"
    DEPENDS metal.doc
    VERBATIM
)
