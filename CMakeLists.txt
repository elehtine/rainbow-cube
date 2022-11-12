cmake_minimum_required(VERSION 3.20)

project(rainbow-cube VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Test Widgets)
qt_standard_project_setup()

add_subdirectory(src/app)
add_subdirectory(src/cube)
add_subdirectory(tests/cube)
