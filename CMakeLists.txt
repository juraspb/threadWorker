cmake_minimum_required(VERSION 3.16)
project(WorkerExample)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
#qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})

qt_wrap_cpp(MOC_SOURCES mainwindow.h worker.h)

add_executable(WorkerExample
    main.cpp
    mainwindow.cpp
    worker.cpp
    ${MOC_SOURCES}
)

target_link_libraries(WorkerExample Qt5::Core Qt5::Widgets)
