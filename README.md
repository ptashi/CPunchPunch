# 🥊 CPunchPunch

**CPunchPunch** is a 2D fighting game developed using **C++**, **Object-Oriented Programming (OOP)**, and **Raylib**.

Set on the University of Connecticut (UConn) campus, players will battle against characters inspired by our team members, with the ultimate goal of defeating our final boss, **Professor Songhan**.

## ⚙️ Installation & Setup

CPunchPunch is developed using **C++ and Raylib**. Follow the instructions below to set up the project on **Windows using Visual Studio Code**.

### 1. Prerequisites

Make sure you have the following installed:

- [Visual Studio Code](https://code.visualstudio.com/)
- **C/C++ Extension** by Microsoft (available in VS Code Extensions)
- [Git](https://git-scm.com/downloads)
- [W64Devkit](https://github.com/skeeto/w64devkit/releases) — C++ compiler and build tools for Windows

After installing W64Devkit, add its `bin` folder to your system's PATH environment variable.

Verify the installations in the VS Code terminal:

```bash
g++ --version
git --version
```

### 2. Clone the Repository

Open the VS Code terminal and run:

```bash
git clone https://github.com/USERNAME/CPunchPunch.git
cd CPunchPunch
```

Replace `USERNAME` with the repository owner's GitHub username.

### 3. Set Up Raylib

We recommend using the [Raylib Quickstart Template](https://github.com/raylib-extras/raylib-quickstart) for the initial build configuration.

1. Download the Raylib Quickstart template.
2. Follow its Windows MinGW-w64 setup instructions.
3. Configure the project to use Raylib with C++.
4. Ensure the Raylib dependencies and build configuration are included in the CPunchPunch project.

**Note:** Raylib is written in C but supports C++. Make sure the project compiles `.cpp` files using `g++`.

### 4. Build & Run

Once Raylib is configured, open the CPunchPunch folder in VS Code.

Use the build task configured for the project (`Ctrl + Shift + B`), or run the appropriate Make command if using the Quickstart Makefile.

Run the generated executable to launch CPunchPunch.

### 5. Troubleshooting

- **`g++` not recognized:** Check that W64Devkit's `bin` folder is added to PATH.
- **`raylib.h` not found:** Verify that Raylib's include directories are configured correctly.
- **Linker errors:** Make sure Raylib and its required Windows libraries are linked correctly.
- **Build errors:** Confirm that the build configuration compiles C++ files rather than only C files.

For additional information, refer to the [Raylib documentation](https://www.raylib.com/).

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
- **Graphics Library:** Raylib
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Game Type:** 2D Fighting Game

## 🚧 Development Status

CPunchPunch is currently in the **planning and early development stage**.

Our initial focus will be on implementing character movement, basic combat, and game visuals. Additional mechanics, character archetypes, and game modes will be considered as development progresses.
