include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_definitions(-DEXPECTED_METAL_MAJOR=${METAL_MAJOR})
add_definitions(-DEXPECTED_METAL_MINOR=${METAL_MINOR})
add_definitions(-DEXPECTED_METAL_PATCH=${METAL_PATCH})

test_units(test.unit Metal "${CMAKE_CURRENT_SOURCE_DIR}/src")
