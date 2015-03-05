# This file is part of mpl2, a free software.
# Use, modification and distribution is subject to the BSD 2-clause license.
# See accompanying file LICENSE for its full text.

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(CompilerFlags)
include(CompilerWarnings)
include(CompilerExtensions)
include(TargetUtilities)

enable_testing()

globally_disable_compiler_extensions()
globally_enable_compiler_warnings()

file(GLOB_RECURSE BOOST_MPL_TEST_HEADERS "*.hpp")
file(GLOB_RECURSE BOOST_MPL_TEST_SOURCES "*.cpp")

include_directories(${BOOST_MPL_INCLUDE_DIRS})
link_directories(${BOOST_MPL_LIBRARY_DIRS})

set(SUPPORTED_STANDARDS "C++98;C++03;C++11;C++14")
foreach(DIALECT ${SUPPORTED_STANDARDS})
    language_dialect_flags("CXX" ${DIALECT} DIALECT_FLAGS)
    foreach(SOURCE ${BOOST_MPL_TEST_SOURCES})
        string(REGEX REPLACE ".*[/\\](.*\)[.]cpp" "\\1_test_${DIALECT}" TARGET ${SOURCE})
        add_binary_target(
            EXECUTABLE ${TARGET}
            LANGUAGE "CXX"
            SOURCES ${SOURCE} ${BOOST_MPL_TEST_HEADERS}
            LIBRARIES ${BOOST_MPL_LIBRARIES}
            ADITIONAL_FLAGS ${DIALECT_FLAGS}
            DEPENDENCIES mpl2
        )
        add_test(${TARGET} ${CMAKE_CURRENT_BINARY_DIR}/${TARGET})
        set(TEST_TARGETS ${TEST_TARGETS} ${TARGET})
    endforeach()
endforeach()

add_custom_target(tests DEPENDS ${TEST_TARGETS})
add_custom_command(
    TARGET tests
    COMMENT "unity tests"
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND}
    ARGS --output-on-failure
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
