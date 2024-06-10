/*
* Player.cpp
* Contains the implementation of the Player class
* Author: Barbatos6669
* Last updated: 6/8/2024
* Known issues: None
*
* This file contains the implementation of the Player class, which is responsible for
* managing the player character in the game.
*/

#include "Player.h"

#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;
using namespace std;

Player::Player() : health(100), maxHealth(100), mana(100), experience(0), level(1), gold(0), speed(100.0f), frameWidth(64), frameHeight(64), currentFrame(0), frameDuration(0.2f)
{
	playerShape.setSize(Vector2f(64, 64));
	playerShape.setFillColor(Color::Green);
	playerShape.setPosition(375.0f, 275.0f);

	// Initialize frames per row (example values)
	framesPerRow = {7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 6, 6, 6, 6, 13, 13, 13, 13, 6}; // Number of frames for each row

	// Resize the vectors based on the number of layers
	int numberOfLayers = 1; // Example value, adjust as needed
	spriteLayers.resize(numberOfLayers);
	textures.resize(numberOfLayers);

	cout << "Player constructor called" << endl;
}

Player::~Player()
{
	cout << "Player destructor called" << endl; // Output a message to the console for debugging purposes
	cleanup(); // Ensure cleanup is called when the class instance is destroyed
}

void Player::initialize()
{
	cout << "Player initialize method called" << endl; // Output a message to the console for debugging purposes

	frameDuration = 0.1f; // Set the frame duration to 0.2 seconds

	health = 100;
	cout << "Player health set to 100" << endl;

	// Load textures for each layer
	if (!textures[0].loadFromFile("assets/textures/player/body/male/light.png"))
	{
		cerr << "Failed to load player base texture!" << endl;
	}

	// Initialize sprites for each layer

	spriteLayers[0].setTexture(textures[0]);
	spriteLayers[0].setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
	spriteLayers[0].setPosition(375.0f, 275.0f);
}

void Player::cleanup()
{
	cout << "Player cleanup method called" << endl; // Output a message to the console for debugging purposes
	// Cleanup player-specific resources here
}

void Player::startPlayer()
{
	cout << "Player start method called" << endl; // Output a message to the console for debugging purposes
	setPlayerState(PlayerState::Idle); // Set the player state to Idle
}

void Player::pausePlayer()
{
	cout << "Player pause method called" << endl; // Output a message to the console for debugging purposes
	// Handle pausing the player, if necessary
}

void Player::resumePlayer()
{
	cout << "Player resume method called" << endl; // Output a message to the console for debugging purposes
	// Handle resuming the player, if necessary
}

void Player::endPlayer()
{
	cout << "Player end method called" << endl; // Output a message to the console for debugging purposes
	setPlayerState(PlayerState::Dead);
}

void Player::handleEvents()
{
	// cout << "Player handle events method called" << endl;
	// Handle player-specific events here
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		playerShape.move(0, -speed * 0.1f); // Move up
		setPlayerState(PlayerState::WalkUp); // Set the player state to Moving
		cout << "Player moving up" << endl; // Output a message to the console for debugging purposes
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		playerShape.move(0, speed * 0.1f); // Move down
		setPlayerState(PlayerState::WalkDown);
		cout << "Player moving down" << endl; // Output a message to the console for debugging purposes
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerShape.move(-speed * 0.1f, 0); // Move left
		setPlayerState(PlayerState::WalkLeft);
		cout << "Player moving left" << endl; // Output a message to the console for debugging purposes
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerShape.move(speed * 0.1f, 0); // Move right
		setPlayerState(PlayerState::WalkRight);
		cout << "Player moving right" << endl; // Output a message to the console for debugging purposes
	}
	else
	{
		setPlayerState(PlayerState::Idle);
		// cout << "Player idle" << endl; // Output a message to the console for debugging purposes
	}
}

void Player::animatePlayer()
{
	if (currentPlayerState == PlayerState::Idle)
	{
		currentRow = 0;
	}
	else if (currentPlayerState == PlayerState::WalkUp)
	{
		currentRow = 8;
	}
	else if (currentPlayerState == PlayerState::WalkDown)
	{
		currentRow = 10;
	}
	else if (currentPlayerState == PlayerState::WalkLeft)
	{
		currentRow = 9;
	}
	else if (currentPlayerState == PlayerState::WalkRight)
	{
		currentRow = 11;
	}

	totalFrames = framesPerRow[currentRow]; // Set totalFrames for the current row
}

void Player::update()
{
	animatePlayer();

	if (totalFrames > 0 && animationClock.getElapsedTime().asSeconds() > frameDuration)
	{
		currentFrame = (currentFrame + 1) % totalFrames; // Loop back to the first frame

		for (auto& sprite : spriteLayers)
		{
			sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, currentRow * frameHeight, frameWidth, frameHeight));
		}

		animationClock.restart();
	}
}

void Player::render(sf::RenderWindow& window)
{
	for (const auto& sprite : spriteLayers)
	{
		window.draw(sprite);
	}
}

void Player::savePlayer()
{
	cout << "Player save method called" << endl; // Output a message to the console for debugging purposes
	// Implement saving player state logic
}

void Player::loadPlayer()
{
	cout << "Player load method called" << endl; // Output a message to the console for debugging purposes
	// Implement loading player state logic
}

int Player::getHealth() const
{
	// cout << "Player getHealth method called" << endl; // Output a message to the console for debugging purposes
	return health; // Return the player's health value
	return 0;
}

int Player::setHealth(int health)
{
	cout << "Player setHealth method called" << endl; // Output a message to the console for debugging purposes
	this->health = health; // Update the health value

	return 0;
}