# Car Game - Console-Based Grid Navigation Game

A challenging C++ console game where players navigate a car through a 7x7 grid maze, avoiding obstacles while collecting coins and trophies to reach the finish line.

## 🎮 Game Overview

Navigate your car through a grid-based map filled with obstacles, collectibles, and challenges. Use strategy and skill to find the optimal path to the finish line while maximizing your score through coin and trophy collection.

### Key Features
- **7x7 Grid Map**: Compact but challenging game board
- **Obstacle Navigation**: Avoid dynamically generated obstacles
- **Collectible System**: Gather coins and trophies for points
- **Leaderboard**: Track high scores and player achievements
- **Automated Pathfinding**: Built-in shortest path calculation
- **Achievement Tracking**: Record and display player accomplishments

## 🏗️ Project Structure

The project is organized into several specialized files, each handling specific game functionality:

### Core Files

#### `main.cpp`
- **Central Hub**: Main entry point and user interface
- **Menu System**: All game menus and display options
- **Game Controller**: Integrates all other components
- **User Interaction**: Primary interface for gameplay

#### `Graph.h`
- **Game Engine**: Core game logic and mechanics
- **Grid Management**: Handles the 7x7 game board
- **Game State**: Manages player position, movement, and game rules
- **Foundation**: Drives all key game processes

#### `Heap.h`
- **Score Management**: Maintains and calculates player scores
- **Leaderboard Logic**: Facilitates score comparisons
- **Pathfinding Algorithm**: Calculates shortest path from current position to finish
- **Game Automation**: Provides automated gameplay assistance

#### `Linked List.h`
- **Achievement System**: Tracks player accomplishments
- **Collectible Counter**: Records coins and trophies collected
- **Data Persistence**: Saves achievement data to leaderboard
- **Progress Tracking**: Maintains historical player performance

#### `Queue.h`
- **Obstacle Generation**: Creates dynamic obstacles on the grid
- **Challenge Creation**: Generates gameplay challenges
- **Map Modification**: Dynamically alters the game environment

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Console/Terminal environment
- Basic understanding of grid-based navigation games

### Installation & Setup

1. **Clone or Download** the project files
2. **Compile** the project:
   ```bash
   g++ -o car_game main.cpp
   ```
3. **Run** the game:
   ```bash
   ./car_game
   ```

## 🎯 How to Play

1. **Start the Game**: Launch from the main menu
2. **Navigate**: Use keyboard controls to move your car
3. **Avoid Obstacles**: Steer clear of generated obstacles
4. **Collect Items**: Gather coins and trophies for points
5. **Reach the Finish**: Successfully navigate to the endpoint
6. **Check Leaderboard**: View your score and achievements

### Game Elements
- **🚗 Player Car**: Your controllable character
- **🚧 Obstacles**: Barriers to avoid
- **🪙 Coins**: Collectible items for points
- **🏆 Trophies**: Special collectibles for bonus points
- **🏁 Finish Line**: Your destination goal

## 🏆 Scoring System

- **Coins Collected**: Base points for each coin
- **Trophies Earned**: Bonus points for special achievements
- **Path Efficiency**: Bonus for optimal routing
- **Completion Time**: Time-based scoring multipliers

## 📊 Features

### Data Structures Used
- **Graph**: For grid representation and pathfinding
- **Heap**: For efficient score management and pathfinding algorithms
- **Linked List**: For achievement tracking and data storage
- **Queue**: For obstacle generation and game state management

### Advanced Features
- Shortest path calculation
- Dynamic obstacle generation
- Persistent leaderboard system
- Achievement tracking
- Score optimization

## 🛠️ Technical Details

### Architecture
The game follows a modular design pattern with clear separation of concerns:
- UI/UX handled in `main.cpp`
- Core logic in `Graph.h`
- Specialized functionality distributed across header files

### Data Management
- Score persistence through heap structure
- Achievement tracking via linked list
- Dynamic content generation using queue system

## 🤝 Contributing

This project structure allows for easy extension and modification:
- Add new obstacle types in `Queue.h`
- Implement new scoring mechanisms in `Heap.h`
- Extend achievement system in `Linked List.h`
- Modify game rules in `Graph.h`

## 📝 Future Enhancements

Potential improvements and additions:
- Larger grid sizes (10x10, 15x15)
- Multiple difficulty levels
- Power-ups and special abilities
- Multiplayer support
- Graphical interface
- Sound effects
- Save/load game state

## 🐛 Troubleshooting

Common issues and solutions:
- **Compilation errors**: Ensure all header files are in the same directory
- **Console display issues**: Verify terminal supports required characters
- **Control problems**: Check keyboard input handling in your environment

**Enjoy navigating through the challenges and collecting those coins! 🚗💨**
