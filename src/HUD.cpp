/*
* HUD.cpp
* Contains the implementation of the HUD class
* Author: Barbatos6669
* Last updated: 6/8/2024
* Known issues: None
*
* This file contains the implementation of the HUD class, which is responsible for
* rendering the heads-up display for the player.
*/

#pragma once

#include "HUD.h"
#include <iostream>
#include "Player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;
using namespace std;

HUD::HUD()
{
}

HUD::~HUD()
{
	cleanup();
}

void HUD::initialize()
{
	cout << "HUD initialize method called" << endl; // Output a message to the console for debugging purposes
	// Initialize the health bar
	healthBar.initialize("assets/textures/healthBar/healthBar_v1.png", 160, 20, 10);
}

void HUD::cleanup()
{
	cout << "HUD cleanup method called" << endl; // Output a message to the console for debugging purposes
	// Cleanup resources if necessary
	healthBar.cleanup();
}

void HUD::handleEvents(Event event)
{
	// Handle events for the HUD
	healthBar.handleEvents(event);
}

void HUD::update(int health)
{
	healthBar.update(health); // Update the health bar with the current health value
}

void HUD::render(RenderWindow& window)
{
	healthBar.render(window); // Render the health bar to the screen
}