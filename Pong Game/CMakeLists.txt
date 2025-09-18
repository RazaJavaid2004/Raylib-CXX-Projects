cmake_minimum_required(VERSION 3.20)
project(PongGame CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(PongGame
  src/main.cpp
  src/ball.cpp
  src/line.cpp
  src/paddle.cpp
  src/score.cpp
)
target_include_directories(PongGame PRIVATE include)

# Try package manager first (e.g., vcpkg), fallback to manual link on Windows
find_package(raylib CONFIG QUIET)
if(raylib_FOUND)
  target_link_libraries(PongGame PRIVATE raylib)
elseif(WIN32)
  target_link_libraries(PongGame PRIVATE raylib opengl32 gdi32 winmm)
endif()