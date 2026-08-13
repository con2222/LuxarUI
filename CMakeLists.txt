cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(LuxUI
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(c2-core-lib)

add_library(LUI STATIC)

target_sources(LUI PRIVATE
    src/lui_widgets.cpp
)

target_include_directories(LUI
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(LUI PUBLIC C2Core)

if(MSVC)
    target_compile_options(LUI PRIVATE /W4 /WX)
else()
    target_compile_options(LUI PRIVATE -Wall -Wextra -Werror)
endif()

# 1. app компилирует ТОЛЬКО main.cpp
add_executable(app src/main.cpp)

# 2. Мы ЛИНКУЕМ библиотеку LUI к нашему приложению app
target_link_libraries(app PRIVATE LUI)
