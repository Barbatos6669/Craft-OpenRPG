#pragma once

/*
	Header file for the GameManager class.

	This class is responsible for managing the game loop, and the game state.
	Including starting the game, updating the game, and ending the game.
	Manages global game settings, and data.
*/

#include <SFML/Graphics/RenderWindow.hpp>

class GameManager
{
	public:
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

	private:
	sf::RenderWindow window;
	bool isRunning;
	bool isPaused;
};