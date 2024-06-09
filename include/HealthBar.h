#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Window/Event.hpp>

using namespace std;
using namespace sf;

class HealthBar
{
	public:
	HealthBar(); // Constructor
	~HealthBar(); // Destructor

	void initialize(const std::string& spriteSheetPath, int frameWidth, int frameHeight, int numFrames); // Initialize with sprite sheet
	void cleanup(); // This method handles the cleanup of resources when the game ends.

	void update(int currentHealth); // Update the game state
	void render(RenderWindow& window); // Render the game state

	void handleEvents(Event event); // Handle events
	void handleContinuousEvents(); // Handle continuous events

	void setHealth(int health); // Set the health value
	int getHealth() const; // Get the health value
	int setFrame(int frameNumber); // Set the frame number

	void setDebugMode(bool debugMode); // Set debug mode flag

	private:
	int health; // The health value
	int maxHealth; // The maximum health value
	int frameWidth; // The width of each frame in the sprite sheet
	int frameHeight; // The height of each frame in the sprite sheet
	int numFrames; // The number of frames in the sprite sheet
	bool debugMode; // Debug mode flag
	Texture texture; // The texture for the sprite sheet
	Sprite sprite; // The sprite for the health bar
};
