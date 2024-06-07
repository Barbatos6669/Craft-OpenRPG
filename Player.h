#pragma once

/*
*   Player:
*
	Contains player-specific properties (health, mana, inventory, etc.).
	Handles player movement, actions, and interactions.
*/

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Player
{
	public:
	enum class PlayerState
	{
		Idle,
		Moving,
		Attacking,
		Dead
	};

	Player(); // Constructor
	~Player(); // Destructor

	// Initialization and cleanup
	void initialize(); // This method is intended to set up the player, such as initializing player properties and resources.
	void cleanup(); // This method handles the cleanup of player resources when the game ends.

	// Player state transitions
	void startPlayer(); // Starts the player and enters the main player loop.
	void pausePlayer(); // Pauses the player.
	void resumePlayer(); // Resumes the player from a paused state.
	void endPlayer(); // Ends the player and exits the main loop.

	// Event handling
	void handleEvents(); // Processes player events such as player input and window events.

	// Player loop Management
	void update(); // Update the player state
	void render(RenderWindow& window); // Render the player state

	// Saving and Loading
	void savePlayer(); // Save the player state
	void loadPlayer(); // Load the player state

	// Getters and Setters for the current player state
	PlayerState getPlayerState() const;
	void setPlayerState(PlayerState playerState);

	private:
	PlayerState currentPlayerState;
	RectangleShape playerShape; // Simple shape to represent the player
	float speed;
};

// Inline method implementations
inline Player::PlayerState Player::getPlayerState() const
{
	return currentPlayerState;
}

inline void Player::setPlayerState(PlayerState playerState)
{
	currentPlayerState = playerState;
}
