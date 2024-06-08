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
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	this->numFrames = numFrames;

	// Load the sprite sheet texture
	if (!texture.loadFromFile(spriteSheetPath))
	{
		cerr << "Failed to load sprite sheet!" << endl;
	}

	// Set up the sprite
	sprite.setTexture(texture);
	setHealth(health); // Set the initial frame based on current health
}

void HealthBar::cleanup()
{
	// Cleanup resources if necessary
}

void HealthBar::update()
{
	// Update logic if necessary (e.g., animations)
}

void HealthBar::render(RenderWindow& window)
{
	window.draw(sprite);
}

void HealthBar::setHealth(int newHealth)
{
	health = newHealth;
	if (health < 0) health = 0;
	if (health > maxHealth) health = maxHealth;

	// Calculate the frame index based on health percentage
	int frameIndex = (health * numFrames) / maxHealth;
	sprite.setTextureRect(IntRect(frameIndex * frameWidth, 0, frameWidth, frameHeight));
}

int HealthBar::getHealth() const
{
	return health;
}