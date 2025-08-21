# 🏀 Bouncing Ball Project

A simple yet extensible bouncing ball simulation built with C++ and raylib.
Designed to showcase modular asset loading, visual debug overlays, and portable build/run workflows.

## 🚀 Features

- Real-time ball physics with gravity and collision response
- Dynamic window resizing and resolution independence
- Visual debug overlay for collision boundaries and velocity vectors
- Modular asset loading with fallback paths
- Cross-platform build automation via batch scripts and VS Code tasks

## 📁 Project Structure

/assets/          # Textures, sounds, fonts
/include/
    ball.h	  # ball class
/src/             # Core logic and helpers
    main.cpp      # Entry point
    ball.cpp/     # Ball physics and rendering
/build/           # Platform-specific build scripts
README.md         
```

## 🛠️ Build & Run

### Prerequisites

- C++17 or later
- raylib installed or included as a submodule
- VS Code (recommended) with C++ extensions
```

### VS Code Tasks

Use `Ctrl+Shift+B` to build and run via preconfigured tasks in `.vscode/tasks.json`.

## 🧠 Debugging

- Toggle overlays with `D` key
- Logs written to `logs/runtime.log`
- Asset loading failures are reported with full path diagnostics

## 📦 Asset Management

Assets are loaded using smart path resolution:

- Checks working directory alignment
- Falls back to default textures if missing
- Logs missing assets with suggestions

## ✨ Future Improvements

- Add multiple balls with collision
- Integrate sound effects
- Export replay data for analysis

## 📜 License

MIT License. See [LICENSE](LICENSE) for details.