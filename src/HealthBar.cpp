/*
* HealthBar.cpp
* Contains the implementation of the HealthBar class
* Author: Barbatos6669
* Last updated: 6/8/2024
* Known issues: None
*
* This file contains the implementation of the HealthBar class, which is responsible for
* rendering the health bar for the player.
*/

#include "HealthBar.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Player.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowBase.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <utility>

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
	setHealth(maxHealth); // Set the initial health value to maxHealth

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

void HealthBar::handleEvents(Event event)
{
	// Handle events for the health bar
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Period)
	{
		debugMode = !debugMode;
		cout << "Debug mode " << (debugMode ? "enabled" : "disabled") << endl;
	}
}

void HealthBar::handleContinuousEvents()
{
	if (debugMode)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			setHealth(health + 10); // Increase health by 10
			health = std::min(maxHealth, health); // Ensure health does not exceed the maximum health value
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			setHealth(health - 10); // Decrease health by 10
			health = std::max(0, health); // Ensure health does not go below 0
		}
	}
}

void HealthBar::setHealth(int newHealth)
{
	cout << "Setting health to: " << newHealth << endl; // Output the new health value to the console for debugging purposes
	this->health = newHealth; // Update the health value
}

int HealthBar::getHealth() const
{
	cout << "Getting health value: " << health << endl; // Output the health value to the console for debugging purposes
	return health; // Return the health value
	return 0;
}

int HealthBar::setFrame(int frameNumber)
{
	cout << "Setting frame to: " << frameNumber << endl; // Output the new frame number to the console for debugging purposes
	sprite.setTextureRect(IntRect(frameNumber * frameWidth, 0, frameWidth, frameHeight)); // Update the sprite frame

	return 0;
}

void HealthBar::setDebugMode(bool debugMode)
{
	this->debugMode = debugMode; // Set the debug mode flag
	cout << "Debug mode set to: " << debugMode << endl; // Output the debug mode flag to the console for debugging purposes
}