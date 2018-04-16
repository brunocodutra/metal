if(NOT CLANG_FORMAT)
    message(WARNING "clang-format not found - target 'test.format' will be unavailable.")
    return()
endif()

test_formatting(test.formatting Metal ${METAL_INCLUDE_DIR})
