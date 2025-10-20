# Find source files
file(GLOB_RECURSE SRCS "*.cpp" "*.c")

add_executable(${PROJECT_NAME} ${SRCS})

target_compile_definitions(${PROJECT_NAME} PRIVATE OPENGL_VERSION_MAJOR=4)
target_compile_definitions(${PROJECT_NAME} PRIVATE OPENGL_VERSION_MINOR=6)

target_include_directories(${PROJECT_NAME} PRIVATE .)
target_include_directories(${PROJECT_NAME} PRIVATE ../libraries/glad/)
target_include_directories(${PROJECT_NAME} PRIVATE ../libraries/entt/single_include)
target_include_directories(${PROJECT_NAME} PRIVATE ../libraries/glfw/include)
target_include_directories(${PROJECT_NAME} PRIVATE ../libraries/fmt/include)

target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt)
