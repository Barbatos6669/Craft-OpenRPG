#pragma once

/*
	Class Summary:

		GameManager class
		- This class is used to manage the game
		- The GameManager class is responsible for initializing, cleaning up, starting, pausing, resuming, and ending the game
		- It handles events, updates the game state, renders the game state, and saves/loads the game state

*/

#include <SFML/Graphics/RenderWindow.hpp>

#include "Player.h"

class GameManager
{
	public:

	enum class GameState
	{
		MainMenu,
		Playing,
		Paused,
		GameOver
	};
	// The constructor initializes the class, and the destructor ensures cleanup when the class instance is destroyed.
	GameManager(); // Constructor
	~GameManager(); // Destructor

	// Initialization and cleanup
	void initialize(); // This method is intended to set up the game, such as initializing game systems and resources.
	void cleanup(); // This method handles the cleanup of resources when the game ends.

	// Game state transitions
	void startGame(); //  Starts the game and enters the main game loop.
	void pauseGame(); // Pauses the game.
	void resumeGame(); // Resumes the game from a paused state.
	void endGame(); // Ends the game and exits the main loop.

	// Event handling
	void handleEvents(); // Processes global events such as player input and window events.

	// Game loop Management
	void update(); // Update the game state
	void render(); // Render the game state

	// Saving and Loading
	void saveGame(); // Save the game state
	void loadGame(); // Load the game state

	// Getters and Setters for the current game state
	GameState getGameState() const;
	void setGameState(GameState gameState);

	private:
	sf::RenderWindow window; // The game window
	bool isRunning; // Is the game running?
	bool isPaused; // Is the game paused?
	GameState currentGameState; // The current game state
	Player player; // The player object
};

// Inline method implementations
inline GameManager::GameState GameManager::getGameState() const
{
	return currentGameState;
}

inline void GameManager::setGameState(GameState gameState)
{
	currentGameState = gameState;
}