include_directories("${PROJECT_SOURCE_DIR}/src")

add_library(my_library "my_library.cpp")

# Add source to this project's executable.
add_executable(main "icp_main.cpp")
target_link_libraries(main my_library)
