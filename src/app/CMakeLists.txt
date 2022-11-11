qt_add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
    cubewindow.cpp
    cubewindow.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE cube Qt6::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
