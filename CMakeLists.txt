cmake_minimum_required(VERSION 3.10)

project(glshooter CXX C) 

add_subdirectory(libraries/glfw)
add_subdirectory(libraries/glm)
add_subdirectory(libraries/glad)
add_subdirectory(libraries/fmt)

set(BIN_DIR bin)
file(MAKE_DIRECTORY ${BIN_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${BIN_DIR})

set(CMAKE_CXX_STANDARD 23)


add_subdirectory(src)
