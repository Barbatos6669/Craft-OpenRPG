/*
* UIManager.cpp
* Contains the implementation of the UIManager class
* Author: Barbatos6669
* Last updated: 6/8/2024
* Known issues: None
*
* This file contains the implementation of the UIManager class, which is responsible for
* managing the user interface elements of the game.
* The UIManager class is responsible for rendering the main menu, playing UI, paused UI, and game over UI.
* The UIManager class is also responsible for handling user input for the UI elements.
*/

// Include the header file for the UIManager class
#include "UIManager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <GameManager.h>
#include <SFML/Window/Event.hpp>

// namespace
using namespace sf;
using namespace std;

UIManager::UIManager()
{
	cout << "UIManager constructor called" << endl; // Output a message to the console for debugging purposes
}

UIManager::~UIManager()
{
	cout << "UIManager destructor called" << endl; // Output a message to the console for debugging purposes
	cleanup(); // Ensure cleanup is called when the class instance is
}

void UIManager::initialize()
{
	cout << "UIManager initialize method called" << endl; // Output a message to the console for debugging purposes
	// Initialize UI-specific properties and resources here

	hud.initialize(); // Initialize the HUD object
}

void UIManager::cleanup()
{
	cout << "UIManager cleanup method called" << endl; // Output a message to the console for debugging purposes
	// Cleanup UI-specific resources here

	hud.cleanup(); // Cleanup the HUD object
}

void UIManager::handleEvents(Event event)
{
	//cout << "UIManager handleEvents method called" << endl; // Output a message to the console for debugging purposes

	hud.handleEvents(event); // Handle events for the HUD
}

void UIManager::update(int health)
{
	//cout << "UIManager update method called" << endl; // Output a message to the console for debugging purposes

	hud.update(health); // Update the HUD with the player's health
}

void UIManager::render(RenderWindow& window)
{
	//cout << "UIManager render method called" << endl; // Output a message to the console for debugging purposes

	hud.render(window); // Render the HUD to the screen
}

void UIManager::setupMainMenu()
{
}

void UIManager::setupPlayingUI()
{
}

void UIManager::setupPausedUI()
{
}

void UIManager::setupGameOverUI()
{
}