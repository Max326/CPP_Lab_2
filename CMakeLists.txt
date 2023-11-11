cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Set OpenGL preference
set(OpenGL_GL_PREFERENCE GLVND)

file(GLOB SOURCES "src/*.cpp")

add_executable(MyExecutable ${SOURCES})