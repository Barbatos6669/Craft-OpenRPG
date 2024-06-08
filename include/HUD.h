#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "HealthBar.h"

using namespace sf;

class HUD
{
	public:
	HUD();
	~HUD();

	void initialize();
	void cleanup();

	void update(int health);
	void render(RenderWindow& window); // Render the HUD to the screen

	private:
	HealthBar healthBar;
};
