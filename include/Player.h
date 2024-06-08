#pragma once

/*
*   Player:
*
	Contains player-specific properties (health, mana, inventory, etc.).
	Handles player movement, actions, and interactions.
*/

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "HealthBar.h"

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

	// Getters and Setters for the player's health
	int getHealth() const;
	void setHealth(int health);
	void takeDamage(int damage);
	void heal(int amount);

	private:
	PlayerState currentPlayerState;
	RectangleShape playerShape; // Simple shape to represent the player
	float speed;

	int health; // The player's health
	int maxHealth; // The player's maximum health
	int mana; // The player's mana
	int experience; // The player's experience points
	int level; // The player's level
	int gold; // The player's gold
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

inline int Player::getHealth() const
{
	return health;
}

inline void Player::setHealth(int health)
{
	health = health;
}

inline void Player::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
}

inline void Player::heal(int amount)
{
	health += amount;

	if (health > maxHealth)
	{
		health = maxHealth;
	}
}
