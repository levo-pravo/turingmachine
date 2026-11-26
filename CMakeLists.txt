cmake_minimum_required(VERSION 3.10)
project(lab3 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(lab3
	src/main.cpp
    src/alphabetdialog.cpp
    src/mainwindow.cpp
    
)

target_link_libraries(lab3 PRIVATE Qt6::Widgets)