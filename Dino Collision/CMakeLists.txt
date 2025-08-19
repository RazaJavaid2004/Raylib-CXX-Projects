cmake_minimum_required(VERSION 3.20)
project(DinoCollision CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(DinoCollision
  src/main.cpp
  src/dino.cpp
)
target_include_directories(DinoCollision PRIVATE include)

# Try package manager first (e.g., vcpkg), fallback to manual link on Windows
find_package(raylib CONFIG QUIET)
if(raylib_FOUND)
  target_link_libraries(DinoCollision PRIVATE raylib)
elseif(WIN32)
  target_link_libraries(DinoCollision PRIVATE raylib opengl32 gdi32 winmm)
endif()