qt_add_executable(test-cube
  testcube.cpp
)
add_test(NAME test-cube COMMAND test-cube)

target_link_libraries(test-cube PRIVATE cube Qt6::Test Qt6::Widgets)
