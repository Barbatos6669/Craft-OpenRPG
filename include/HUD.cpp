#include "HUD.h"

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Player.h>

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

void HUD::update(int health)
{
	healthBar.setHealth(health); // Update the health bar with the player's health
}

void HUD::render(RenderWindow& window)
{
	healthBar.render(window); // Render the health bar to the screen
}