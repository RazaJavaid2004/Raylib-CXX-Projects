# 🎮 C++ & Raylib Game Development Projects

Welcome to my **Raylib C++** repository! This collection showcases my journey through 2D game development, computer graphics, and object-oriented programming in C++ using the [raylib](https://www.raylib.com/) library. Each folder is a standalone project progressing from basic window initialization to complete mini-games.

## 📂 Projects Overview

| Project | Description | Key Concepts | 
| ----- | ----- | ----- | 
| **1. [Hello Raylib](./Hello%20Raylib)** | A starter template project to verify compiler and library setup. | Window initialization, basic game loop, rendering text/shapes. | 
| **2. [Bouncing Ball](./Bouncing%20Ball)** | A physics simulation of a ball bouncing within screen boundaries. | Velocity vectors, boundary collision, OOP (`Ball` class), frame-time updates. | 
| **3. [Raylib Buttons](./Raylib%20Buttons)** | An interactive UI demonstration featuring custom-textured menu buttons. | Texture loading, mouse input detection, hover/click states, UI management. | 
| **4. [Dino Collision](./Dino%20Collision)** | A 2D sprite collision detection demo using custom dinosaur textures. | Sprite rendering, bounding-box (AABB) collision detection, asset management. | 
| **5. [Pong Game](./Pong%20Game)** | A complete recreation of the classic arcade game Pong. | Multi-object interaction (`Ball`, `Paddle`, `Score`, `Line`), game state, score tracking. | 

## 🗂️ Repository Architecture

Most projects in this repository follow a clean, modular C++ directory structure configured for **CMake** and **VS Code**:

```
├── Project Name/
│   ├── .vscode/          # VS Code debugging & task configurations
│   ├── assets/           # Game textures, sprites, and backgrounds (where applicable)
│   ├── include/          # Header files (.h)
│   ├── src/              # Source implementation files (.cpp)
│   ├── build.bat         # Quick-build batch script for Windows
│   └── CMakeLists.txt    # CMake build configuration
├── .gitignore
└── LICENSE

```

## ⚙️ Prerequisites

To build and run these projects on your local machine, ensure you have the following installed:

* **C++ Compiler:** MinGW-w64 (GCC) or MSVC supporting C++17 or higher.

* **CMake:** Version 3.15+ (configured with version 4.x support).

* **Raylib:** Installed and accessible via your system paths or CMake package manager.

* **VS Code** *(Optional)*: With the *C/C++* and *CMake Tools* extensions installed.

## 🚀 Getting Started

### 1. Clone the Repository

```
git clone https://github.com/RazaJavaid2004/Raylib-CXX-Projects.git
cd your-repo-name

```

### 2. Building a Project

You can build any of the projects using either the included batch scripts (on Windows) or standard CMake commands.

#### **Option A: Using the Quick Build Script (Windows)**

Navigate to any project folder and run `build.bat` (or `run.bat` for *Hello Raylib*):

```
cd "Pong Game"
.\build.bat

```

#### **Option B: Using CMake Manually**

```
cd "Pong Game"
mkdir -p build
cd build
cmake ..
cmake --build .

```

#### **Option C: Using VS Code**

1. Open the specific project folder (e.g., `Pong Game/`) in **VS Code**.

2. Press `Ctrl + Shift + B` to run the pre-configured build task, or press `F5` to build and launch with the debugger.

## 🛠️ Pro-Tip Note on `build/` Directories

> **Note:** If you clone this repository onto a different machine, it is recommended to delete the existing `build/` folder inside a project before compiling so CMake can generate fresh cache files matching your local compiler paths.

## 📜 License

This repository is licensed under the terms found in the [LICENSE](./LICENSE) file.
