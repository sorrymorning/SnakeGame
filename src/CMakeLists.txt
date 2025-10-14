cmake_minimum_required(VERSION 3.16)
project(SimpleQtApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED    COMPONENTS Core Widgets)

qt_standard_project_setup()

add_executable(SimpleQtApp gui/desktop/main.cc gui/desktop/window.cc)

target_link_libraries(SimpleQtApp PRIVATE Qt6::Core Qt6::Widgets)