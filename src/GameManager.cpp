/*
* GameManager.cpp
* Contains the implementation of the GameManager class
* Author: Barbatos6669
* Last updated: 6/8/2024
* Known issues: None
*
* This file contains the implementation of the GameManager class, which is responsible for
* managing the game state and running the game loop.
*/

#include "GameManager.h"
#include <iostream>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "HUD.h"

using namespace sf;
using namespace std;

GameManager::GameManager() 
	: window(VideoMode(800, 600), "CRAFT-OpenRPG"), isRunning(false), isPaused(false), currentGameState(GameState::MainMenu)
{
	cout << "GameManager constructor called" << endl; // Output a message to the console for debugging purposes

	window.setFramerateLimit(60); // Set the frame rate limit to 60 FPS
	cout << "Frame rate limit set to 60 FPS" << endl; // Output a message to the console for debugging purposes
}

GameManager::~GameManager()
{
	cout << "GameManager destructor called" << endl; // Output a message to the console for debugging purposes
	cleanup(); // Ensure cleanup is called when the class instance is destroyed
}

void GameManager::initialize()
{
	cout << "Initialize method called" << endl; // Output a message to the console for debugging purposes

	// Initialize game systems and resources here
	isRunning = true; // Set the game to running
	cout << "Game is running" << endl; // Output a message to the console for debugging purposes

	player.initialize(); // Initialize the player object
	hud.initialize(); // Initialize the HUD object
}

void GameManager::cleanup()
{
	cout << "Cleanup method called" << endl; // Output a message to the console for debugging purposes

	// Cleanup resources here
	player.cleanup(); // Cleanup the player object
	hud.cleanup(); // Cleanup the HUD object
	isRunning = false; // Set the game to not running
}

void GameManager::startGame()
{
	cout << "Start game method called" << endl; // Output a message to the console for debugging purposes

	isRunning = true; // Set the game to running
	isPaused = false; // Set the game to not paused
	cout << "Game is running" << endl; // Output a message to the console for debugging purposes

	setGameState(GameState::Playing); // Set the game state to Playing

	// Main game loop
	while (isRunning)
	{
		handleEvents(); // Handle events
		if (!isPaused)
		{
			update(); // Update the game state
			render(); // Render the game state
		}
	}
}

void GameManager::pauseGame()
{
	cout << "Pause game method called" << endl; // Output a message to the console for debugging purposes

	isPaused = true; // Set the game to paused
	setGameState(GameState::Paused); // Set the game state to Paused
}

void GameManager::resumeGame()
{
	cout << "Resume game method called" << endl; // Output a message to the console for debugging purposes

	isPaused = false; // Set the game to not paused
	setGameState(GameState::Playing); // Set the game state to Playing
}

void GameManager::endGame()
{
	cout << "End game method called" << endl; // Output a message to the console for debugging purposes

	isRunning = false; // Set the game to not running
	setGameState(GameState::GameOver); // Set the game state to GameOver
}

void GameManager::handleEvents()
{
	// cout << "Handle events method called" << endl; // Output a message to the console for debugging purposes

	Event event; // Create an event object

	// Poll for events
	while (window.pollEvent(event))
	{
		// Handle events
		if (event.type == Event::Closed)
		{
			endGame(); // End the game if the window is closed
		}

		// Handle Keyboard Input
		if (event.type == Event::KeyPressed)
		{
			// Check for specific key presses
			if (event.key.code == Keyboard::Escape)
			{
				if (isPaused)
				{
					resumeGame(); // Resume the game if paused
				}
				else
				{
					pauseGame(); // Pause the game if not paused
				}
			}
		}
	}

	player.handleEvents(); // Handle player-specific events
	hud.handleEvents(event); // Handle HUD events
}

void GameManager::update()
{
	// cout << "Update method called" << endl; // Output a message to the console for debugging purposes
	player.update(); // Update the player object
	hud.update(player.getHealth()); // Update the HUD with the player's health
}

void GameManager::render()
{
	// cout << "Render method called" << endl; // Output a message to the console for debugging purposes

	window.clear(); // Clear the window

	player.render(window); // Render the player object

	hud.render(window); // Render the HUD object

	window.display(); // Display the rendered frame
}

void GameManager::saveGame()
{
	cout << "Save game method called" << endl; // Output a message to the console for debugging purposes
}

void GameManager::loadGame()
{
	cout << "Load game method called" << endl; // Output a message to the console for debugging purposes
}