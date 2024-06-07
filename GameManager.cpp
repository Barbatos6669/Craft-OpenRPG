#include "GameManager.h"
#include <iostream>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;
using namespace std;

GameManager::GameManager() : window(sf::VideoMode(800, 600), "CRAFT-OpenRPG"), isRunning(false), isPaused(false), currentGameState(GameState::MainMenu)
{
	cout << "GameManager constructor called" << endl;
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
}

void GameManager::cleanup()
{
	cout << "Cleanup method called" << endl; // Output a message to the console for debugging purposes

	// Cleanup resources here
	isRunning = false; // Set the game to not running
}

void GameManager::startGame()
{
	cout << "Start game method called" << endl; // Output a message to the console for debugging purposes

	isRunning = true; // Set the game to running
	isPaused = false; // Set the game to not paused

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
	cout << "Handle events method called" << endl; // Output a message to the console for debugging purposes

	Event event; // Create an event object

	// Poll for events
	while (window.pollEvent(event))
	{
		// Handle events
		if (event.type == Event::Closed)
		{
			endGame(); // End the game if the window is closed
		}
		// a placeholder for handling other events
	}
}

void GameManager::update()
{
	cout << "Update method called" << endl; // Output a message to the console for debugging purposes
}

void GameManager::render()
{
	cout << "Render method called" << endl; // Output a message to the console for debugging purposes

	window.clear(); // Clear the window

	// Placeholder for rendering game objects

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