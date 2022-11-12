add_library(cube STATIC
    cube.cpp
    cube.h
    cubebuilder.cpp
    cubebuilder.h
    face.h
    face.cpp
)

target_link_libraries(cube PRIVATE Qt6::Widgets)
target_include_directories(cube INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
