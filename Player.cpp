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
	playerShape.setSize(Vector2f(50.0f, 50.0f)); // 50x50 square
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
	cout << "Player handle events method called" << endl;
	// Handle player-specific events here
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		playerShape.move(0, -speed * 0.1f); // Move up
		setPlayerState(PlayerState::Moving); // Set the player state to Moving
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		playerShape.move(0, speed * 0.1f); // Move down
		setPlayerState(PlayerState::Moving);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerShape.move(-speed * 0.1f, 0); // Move left
		setPlayerState(PlayerState::Moving);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerShape.move(speed * 0.1f, 0); // Move right
		setPlayerState(PlayerState::Moving);
	}
	else
	{
		setPlayerState(PlayerState::Idle);
	}
}

void Player::update()
{
	cout << "Player update method called" << endl; // Output a message to the console for debugging purposes
	// Update player state and properties
}

void Player::render(RenderWindow& window)
{
	cout << "Player render method called" << endl; // Output a message to the console for debugging purposes
	window.draw(playerShape); // Render the player shape
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