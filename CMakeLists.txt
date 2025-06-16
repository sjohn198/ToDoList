cmake_minimum_required(VERSION 3.14)
project(ToDoList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(ftxui)

# --------------------------------------------------
# 1) Gather your sources and headers in src/
# --------------------------------------------------
# (you don’t strictly need the headers in the target’s
# source list, but some IDEs like to see them)
file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE HDR_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# --------------------------------------------------
# 2) Define the executable with ALL your code
# --------------------------------------------------
add_executable(todolist
  main.cpp
  ${SRC_FILES}
  ${HDR_FILES}
)

# --------------------------------------------------
# 3) Make sure the compiler can find your headers
# --------------------------------------------------
target_include_directories(todolist
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# --------------------------------------------------
# 4) FTXUI flags and libraries
# --------------------------------------------------
target_compile_options(todolist
  PRIVATE
    -g
    -Wall
)

target_link_libraries(todolist
  PRIVATE
    ftxui::screen
    ftxui::dom
    ftxui::component
)
