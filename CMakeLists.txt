cmake_minimum_required(VERSION 3.14)
project(ToDoList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG main
)
FetchContent_MakeAvailable(ftxui)

add_executable(todolist main.cpp)

target_compile_options(todolist PRIVATE -g -Wall)

target_link_libraries(todolist PRIVATE ftxui::screen ftxui::dom ftxui::component)