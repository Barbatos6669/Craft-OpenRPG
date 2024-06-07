#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "GameManager.h"

using namespace sf;
using namespace std;

int main()
{
	// Create a GameManger instance
	GameManager gameManager;

	gameManager.initialize(); // Initialize the game

	gameManager.startGame(); // Start the game

	gameManager.cleanup(); // Cleanup the game

	return 0;
}