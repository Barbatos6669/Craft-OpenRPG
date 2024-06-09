#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "HealthBar.h"

using namespace sf;

class HUD
{
	public:
	HUD();
	~HUD();

	void initialize(); // Initialize the HUD
	void cleanup(); // Cleanup the HUD

	void handleEvents(Event event); // Handle events for the HUD

	void update(int health); // Update the HUD
	void render(RenderWindow& window); // Render the HUD to the screen

	private:
	HealthBar healthBar; // The health bar for the player
};
