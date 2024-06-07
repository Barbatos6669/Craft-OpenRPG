/*
	This code represents a C++ implementation of a game manager class. The GameManager
	class provides methods for initializing, cleaning up, starting, pausing, resuming,
	and ending the game. It also handles events, updates the game state, and renders the game objects.
	The constructor initializes the game window with a specified size and title.
	The destructor performs cleanup tasks when the class instance is destroyed.
	The initialize method initializes game systems and resources, setting the game to running.
	The cleanup method cleans up resources and sets the game to not running.
	The startGame method starts the game loop, handling events, updating the game state,
	and rendering the game objects. The loop continues as long as the game is running and not paused.
	The pauseGame method pauses the game by setting the isPaused flag to true and the game state to Paused.
	The resumeGame method resumes the game by setting the isPaused flag to false and the game state to Playing.
	The endGame method ends the game by setting the isRunning flag to false and the game state to GameOver.
	The handleEvents method handles events such as window closure. Currently,
	it checks for the window close event and ends the game if the window is closed.
	The update method updates the game state. Currently, it is empty and can be expanded to include game logic and calculations.
	The render method clears the window, renders the game objects (placeholder), and displays the rendered frame.
	The saveGame and loadGame methods are placeholders for saving and loading game data, respectively.
	This code provides a basic structure for managing a game, handling events, updating the game state, and rendering the game objects. It can be expanded upon to add more functionality and game-specific logic.

*/

#include "GameManager.h"
#include <iostream>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

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
	player.initialize(); // Initialize the player object
}

void GameManager::cleanup()
{
	cout << "Cleanup method called" << endl; // Output a message to the console for debugging purposes

	// Cleanup resources here
	player.cleanup(); // Cleanup the player object
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
}

void GameManager::update()
{
	// cout << "Update method called" << endl; // Output a message to the console for debugging purposes
	player.update(); // Update the player object
}

void GameManager::render()
{
	// cout << "Render method called" << endl; // Output a message to the console for debugging purposes

	window.clear(); // Clear the window

	player.render(window); // Render the player object

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