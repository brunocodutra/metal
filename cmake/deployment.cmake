# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

if(WIN32 AND NOT CYGWIN)
  set(METAL_CMAKE_INSTALL_DIR_DEF CMake)
else()
  set(METAL_CMAKE_INSTALL_DIR_DEF lib/cmake/Metal)
endif()

set(METAL_CMAKE_INSTALL_DIR ${METAL_CMAKE_INSTALL_DIR_DEF} CACHE PATH
    "installation directory for Metal CMake files"
)

set(METAL_INCLUDE_INSTALL_DIR include CACHE PATH
    "installation directory for Metal header files"
)

foreach(_ INCLUDE CMAKE)
  if(NOT IS_ABSOLUTE "${METAL_${_}_INSTALL_DIR}")
    set(METAL_${_}_INSTALL_DIR
        "${CMAKE_INSTALL_PREFIX}/${METAL_${_}_INSTALL_DIR}"
    )
  endif()
endforeach()

file(RELATIVE_PATH METAL_INCLUDE_DIRS
    "${METAL_CMAKE_INSTALL_DIR}" "${METAL_INCLUDE_INSTALL_DIR}"
)

set(METAL_INCLUDE_DIRS "\${METAL_CMAKE_DIR}/${METAL_INCLUDE_DIRS}")

configure_file(cmake/MetalConfig.cmake.in
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfig.cmake"
    @ONLY
)

configure_file(cmake/MetalConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfigVersion.cmake"
    @ONLY
)

install(DIRECTORY
    "${METAL_INCLUDE_DIR}"
    DESTINATION "${METAL_INCLUDE_INSTALL_DIR}"
)

install(FILES
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfig.cmake"
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfigVersion.cmake"
    DESTINATION "${METAL_CMAKE_INSTALL_DIR}"
)
