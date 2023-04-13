cmake_minimum_required(VERSION 3.23)
project(le_gravity_simulator)

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(le_gravity_simulator main.cpp Renderer.cpp Renderer.h IButtonHandler.h IDrawableObject.h)
target_link_libraries(le_gravity_simulator ${SDL2_LIBRARIES})
