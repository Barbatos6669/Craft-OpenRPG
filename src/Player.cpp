#include "Player.h"

#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;
using namespace std;

Player::Player() : currentPlayerState(PlayerState::Idle), speed(100.0f)
{
	playerShape.setSize(Vector2f(16, 16)); // 50x50 square
	playerShape.setFillColor(Color::Green); //
	playerShape.setPosition(375.0f, 275.0f); // Center of 800x600 window
	cout << "Player constructor called" << endl; // Output a message to the console for debugging purposes
}

Player::~Player()
{
	cout << "Player destructor called" << endl; // Output a message to the console for debugging purposes
	cleanup(); // Ensure cleanup is called when the class instance is destroyed
}

void Player::initialize()
{
	cout << "Player initialize method called" << endl; // Output a message to the console for debugging purposes

	// Initialize player-specific properties and resources here
	health = 100;

	// Initialize the health bar
	healthBar.initialize("assets/textures/healthBar/healthBar_v1.png", 160, 20, 10);
	healthBar.setHealth(health); // Set the health bar to the player's health
}

void Player::cleanup()
{
	cout << "Player cleanup method called" << endl; // Output a message to the console for debugging purposes
	// Cleanup player-specific resources here
	healthBar.cleanup(); // Cleanup the health bar
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
		setPlayerState(PlayerState::Moving); // Set the player state to Moving
		cout << "Player moving up" << endl; // Output a message to the console for debugging purposes
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		playerShape.move(0, speed * 0.1f); // Move down
		setPlayerState(PlayerState::Moving);
		cout << "Player moving down" << endl; // Output a message to the console for debugging purposes
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerShape.move(-speed * 0.1f, 0); // Move left
		setPlayerState(PlayerState::Moving);
		cout << "Player moving left" << endl; // Output a message to the console for debugging purposes
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerShape.move(speed * 0.1f, 0); // Move right
		setPlayerState(PlayerState::Moving);
		cout << "Player moving right" << endl; // Output a message to the console for debugging purposes
	}
	else
	{
		setPlayerState(PlayerState::Idle);
	}
}

void Player::update()
{
	// cout << "Player update method called" << endl; // Output a message to the console for debugging purposes
	// Update player state and properties
	healthBar.update(health); // Update the health bar
}

void Player::render(RenderWindow& window)
{
	// cout << "Player render method called" << endl; // Output a message to the console for debugging purposes
	window.draw(playerShape); // Render the player shape
	healthBar.render(window); // Render the health bar
}

void Player::savePlayer()
{
	cout << "Player save method called" << endl;
	// Implement saving player state logic
}

void Player::loadPlayer()
{
	cout << "Player load method called" << endl;
	// Implement loading player state logic
}