# Style Guidelines

To maintain a clean, readable, and consistent codebase, please adhere to the following style guidelines when contributing to CRAFT-OpenRPG.

## Naming Conventions

### 1. **Variables and Attributes:**
   - Use `camelCase` for variable names.
   - Example:
     ```cpp
     int playerHealth;
     float itemWeight;
     ```

### 2. **Classes and Structs:**
   - Use `PascalCase` for class and struct names.
   - Example:
     ```cpp
     class GameManager;
     struct PlayerData;
     ```

### 3. **Functions and Methods:**
   - Use `camelCase` for function and method names.
   - Example:
     ```cpp
     void initializeGame();
     int calculateScore();
     ```

### 4. **Constants and Macros:**
   - Use `UPPERCASE_WITH_UNDERSCORES` for constants and macros.
   - Example:
     ```cpp
     const int MAX_PLAYERS = 4;
     #define SCREEN_WIDTH 800
     ```

## File Structure

### 1. **Directory Layout:**
   - Organize files into directories based on their type and functionality.
     ```
     CRAFT-OpenRPG/
     ├── assets/
     │   ├── music/
     │   ├── textures/
     │   └── fonts/
     ├── include/
     │   ├── Ability.h
     │   ├── Armor.h
     │   ├── CombatManager.h
     │   ├── Enemy.h
     │   ├── GameManager.h
     │   ├── HUD.h
     │   ├── Inventory.h
     │   ├── Item.h
     │   ├── NPC.h
     │   ├── Player.h
     │   ├── Quest.h
     │   ├── UIManager.h
     │   ├── Weapon.h
     │   └── World.h
     ├── src/
     │   ├── GameManager.cpp
     │   ├── Player.cpp
     │   ├── UIManager.cpp
     │   └── main.cpp
     ├── lib/
     ├── .github/
     ├── build/
     ├── Debug/
     ├── x64/
     ├── CRAFT.sln
     ├── CRAFT.vcxproj
     ├── CRAFT.vcxproj.filters
     ├── CRAFT.vcxproj.user
     ├── README.md
     ├── LICENSE
     ├── CONTRIBUTING.md
     ├── enemies.txt
     ├── foreground.txt
     └── Map.txt
     ```

### 2. **Header Files:**
   - Place header files in the `include` directory.
   - Use `#pragma once` to prevent multiple inclusions.
   - Example:
     ```cpp
     #pragma once

     class GameManager {
         // class definition
     };
     ```

### 3. **Source Files:**
   - Place source files in the `src` directory.
   - Include corresponding header files at the top.
   - Example:
     ```cpp
     #include "../include/GameManager.h"
     #include <iostream>

     // method implementations
     ```

## Comments

### 1. **File Headers:**
   - Include a brief description at the top of each file.
   - Example:
     ```cpp
     /*
      * GameManager.h
      * This file contains the declaration of the GameManager class, responsible for managing the game state and main loop.
      */
     ```

### 2. **Class and Method Documentation:**
   - Provide a brief description of each class and method.
   - Example:
     ```cpp
     // The GameManager class handles the game loop and state transitions.
     class GameManager {
         public:
             // Initializes the game.
             void initializeGame();

             // Updates the game state.
             void updateGame();
     };
     ```

### 3. **Inline Comments:**
   - Use inline comments to explain complex logic and important details.
   - Example:
     ```cpp
     void GameManager::initializeGame() {
         // Initialize player and enemy objects.
         player.initialize();
         enemy.initialize();
     }
     ```

## Code Formatting

### 1. **Indentation:**
   - Use 4 spaces for indentation. Do not use tabs.
   - Example:
     ```cpp
     if (condition) {
         // code block
     }
     ```

### 2. **Braces:**
   - Use Allman style for braces.
   - Example:
     ```cpp
     if (condition)
     {
         // code block
     }
     else
     {
         // code block
     }
     ```

### 3. **Line Length:**
   - Limit lines to 80 characters when possible. Break long lines for readability.
   - Example:
     ```cpp
     void someFunction()
     {
         if (longCondition || anotherLongCondition)
         {
             // code block
         }
     }
     ```

## Miscellaneous

### 1. **Avoid Magic Numbers:**
   - Use named constants instead of magic numbers.
   - Example:
     ```cpp
     const int MAX_HEALTH = 100;
     player.setHealth(MAX_HEALTH);
     ```

### 2. **Error Handling:**
   - Use exceptions for error handling.
   - Example:
     ```cpp
     if (!file.open())
     {
         throw std::runtime_error("Failed to open file");
     }
     ```

### 3. **Include Guards:**
   - Always use include guards in header files.
   - Example:
     ```cpp
     #pragma once

     // header file content
     ```

By following these guidelines, we can ensure that our codebase remains clean, consistent, and easy to maintain. Thank you for your contributions and for helping us maintain a high standard of code quality in CRAFT-OpenRPG!

---



