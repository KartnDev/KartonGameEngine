cmake_minimum_required(VERSION 3.16)
project(KartonGameEngine)

set(CMAKE_CXX_STANDARD 20)


add_executable(KartonGameEngine KartonGameEngine/main.cpp)
target_link_libraries(KartonGameEngine -lOpenGl32 -lfreeGLUT)