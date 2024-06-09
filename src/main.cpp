/*
* Main.cpp
* Contains the implementation of the main function
* Author: Barbatos6669
* Last updated: 6/8/2024
* Known issues: None
*
* This file contains the implementation of the main function, which is the entry point for the program.
* It creates an instance of the GameManager class and runs the game loop.
*/

#include "GameManager.h"

using namespace sf;
using namespace std;

int main()
{
	// Create a GameManger instance
	GameManager gameManager;

	gameManager.initialize(); // Initialize the game

	gameManager.startGame(); // Start the game

	gameManager.cleanup(); // Cleanup the game

	return 0;
}