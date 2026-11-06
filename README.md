# 🥊 CPunchPunch

**CPunchPunch** is a 2D fighting game developed using **C++**, **Object-Oriented Programming (OOP)**, and **Raylib**.

Set on the University of Connecticut (UConn) campus, players will battle against characters inspired by our team members, with the ultimate goal of defeating our final boss, **Professor Songhan**.

## ⚙️ Installation & Setup

CPunchPunch is developed using **C++ and Raylib**. Follow the instructions below to set up the project on **Windows using Visual Studio Code**.

### 1. Prerequisites

Make sure you have the following installed:

- [Visual Studio Code](https://code.visualstudio.com/)
- **C/C++ Extension** by Microsoft
- **CMake Tools Extension** by Microsoft
- [Git](https://git-scm.com/downloads)
- [MSYS2](https://www.msys2.org/)

Open the **MSYS2 MINGW64** terminal and install the required development tools:

```bash
pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja git
```

Verify that the tools are installed:

```bash
g++ --version
cmake --version
ninja --version
git --version
```

### 2. Clone the Repository

Open your terminal and run:

```bash
git clone https://github.com/USERNAME/CPunchPunch.git
cd CPunchPunch
```

Replace `USERNAME` with the repository owner's GitHub username.

### 3. Configure Raylib

Raylib is automatically downloaded and configured through **CMake**, so there is no need to install it manually.

From the main `CPunchPunch` directory, run:

```bash
cmake -S . -B build -G Ninja
```

This configures the project and downloads Raylib 5.5 during the initial setup.

### 4. Build & Run

Compile the game:

```bash
cmake --build build
```

Launch CPunchPunch:

```bash
./build/CPunchPunch.exe
```

**For subsequent runs**, after making changes to the code, simply run:

```bash
cmake --build build
./build/CPunchPunch.exe
```

All commands should be run from the main `CPunchPunch` directory using the **MSYS2 MINGW64 terminal**.

### 5. Troubleshooting

- **`g++` not recognized:** Make sure you are using the MSYS2 MINGW64 environment and have installed the compiler.
- **`raylib.h` not found:** Verify that CMake configured successfully. If the project builds but VS Code still shows an error, configure IntelliSense to use the CMake Tools extension.
- **Missing `CMakeCache.txt`:** Run `cmake -S . -B build -G Ninja` before building.
- **Build errors:** Verify that CMake, Ninja, and the C++ compiler are installed correctly.

**Note:** The `build/` directory is automatically generated and should be included in `.gitignore`.

For additional information, refer to the [Raylib documentation](https://www.raylib.com/).

---

## 🎮 Game Mechanics

### Visuals

- **Backgrounds:** Fighting arenas will feature recognizable locations around the UConn campus.
- **Characters:** Playable characters will be pixelated versions of our team members.
- **Character Archetypes:** We may implement four different character archetypes, each with unique fighting styles and abilities.
- **Final Boss:** Professor Songhan will serve as the final opponent.

### Movement & Combat

- Players will use the **arrow keys (↑ ↓ ← →)** for basic character movement.
- Basic attacks and combat mechanics will be implemented.
- Additional features, such as attack combos and special abilities, may be introduced in future development.

## 🏆 Game Modes

We are currently considering two possible directions for the game.

### Option 1: Championship Mode (Local Multiplayer)

- Two players compete against each other using the same keyboard.
- Players battle through a championship-style tournament.
- The final championship opponent will be Professor Songhan.

### Option 2: Story Mode (Single Player)

- Players progress through different levels set around UConn.
- Each level features NPC opponents that players must defeat to advance.
- The final level will feature a boss fight against Professor Songhan.

Both game modes are currently being considered, and the final direction will depend on our development progress and available time.

## 🛠️ Technologies

- **Language:** C++
- **Graphics Library:** Raylib 5.5
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Build System:** CMake + Ninja
- **Development Environment:** Visual Studio Code
- **Game Type:** 2D Fighting Game

## 🚧 Development Status

CPunchPunch is currently in the **planning and early development stage**.

Our initial focus will be on implementing character movement, basic combat, and game visuals. Additional mechanics, character archetypes, and game modes will be considered as development progresses.
