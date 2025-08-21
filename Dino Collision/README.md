# 🦖 Dino Collision

A lightweight raylib-based demo showcasing basic collision detection and sprite rendering using a dino texture.
Built for clarity, portability, and runtime feedback.

---

## 📁 Project Structure

DinoCollision/
├── src/                  # Source files
│   ├── main.cpp          # Entry point
│   └── dino.cpp          # Dino logic and collision
├── include/              # Header files
│   └── dino.h            # Dino class/interface
├── assets/
│   └── texture/
│       └── dino.png      # Dino sprite texture
├── build/                # CMake build output
│   └── DinoCollision.exe # Final executable
├── build.bat             # Windows build script
├── CMakeLists.txt        # CMake configuration
└── README.md             # Project documentation

## 🚀 Getting Started

### Prerequisites

- [raylib](https://www.raylib.com/) installed and available to CMake
- CMake 3.15+
- A C++17-compatible compiler (e.g., MSVC, g++, clang)

### Build Instructions (Windows)

1. Run the build script:build.bat

2. Executable will be generated in the `build/` folder:build/DinoCollision.exe

---

## 🎮 Gameplay Overview

* Loads a dino sprite from `assets/textures/dino.png`
* Moves the dino using arrow keys
* Detects collisions with screen boundaries
* Displays debug overlay for position and collision status

---

## 🛠️ Development Notes

* Asset paths are resolved relative to the executable's working directory
* Modular design: `dino.cpp` handles movement and collision logic
* Visual debug overlays can be extended for runtime diagnostics
* Build script automates CMake configuration and asset copying

---

## 📌 TODO

* Add obstacle collision
* Implement animation frames
* Refactor asset loader for cross-platform support

---

## 📄 License

This project is released under the MIT License. See [LICENSE](LICENSE) for details.
