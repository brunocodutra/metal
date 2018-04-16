add_subdirectory(unit)
add_subdirectory(header)
add_subdirectory(formatting)
add_subdirectory(deployment)

add_custom_target(tests DEPENDS
    test.unit
    test.header
    test.formatting
    test.deployment
)
