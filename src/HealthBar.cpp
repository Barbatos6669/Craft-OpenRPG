#include "HealthBar.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

HealthBar::HealthBar()
	: health(100), maxHealth(100), frameWidth(0), frameHeight(0), numFrames(0)
{
}

HealthBar::~HealthBar()
{
	cleanup();
}

void HealthBar::initialize(const string& spriteSheetPath, int frameWidth, int frameHeight, int numFrames)
{
	cout << "Initializing health bar..." << endl; // Output a message to the console for debugging purposes

	// Initialize the health bar with the sprite sheet
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	this->numFrames = numFrames;

	if (!texture.loadFromFile(spriteSheetPath))
	{
		cerr << "Failed to load sprite sheet!" << std::endl;
	}
	else
	{
		cout << "Loaded sprite sheet successfully!" << endl;
	}

	sprite.setTexture(texture); // Set the texture for the sprite
	sprite.setTextureRect(IntRect(0, 0, frameWidth, frameHeight)); // Display the first frame
	sprite.setPosition(0, 0); // Adjust as needed
}

void HealthBar::cleanup()
{
	// Cleanup resources if necessary
}

void HealthBar::update(int currentHealth)
{
	health = currentHealth; // Update the health value

	// Ensure health does not go below 0 or exceed the maximum health value
	if (health < 0)
	{
		health = 0; // Ensure health does not go below 0
	}
	else if (health > maxHealth)
	{
		health = maxHealth; // Ensure health does not exceed the maximum health value
	}

	// Update the sprite frame based on current health
	int frameIndex = static_cast< int >((static_cast< float >(health) / maxHealth) * (numFrames - 1)); // Calculate the frame index based on health
	sprite.setTextureRect(IntRect(frameIndex * frameWidth, 0, frameWidth, frameHeight)); // Update the sprite frame

	// cout << health << "/ " << maxHealth << "FrameIndex: " << frameIndex << endl; // Output the health value to the console for debugging purposes
}

void HealthBar::render(RenderWindow& window)
{
	window.draw(sprite); // Render the health bar sprite
}

void HealthBar::setHealth(int newHealth)
{
	this->health = health; // Update the health value
}

int HealthBar::getHealth() const
{
	return health; // Return the health value
}