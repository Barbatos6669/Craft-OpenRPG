#include "UIManager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <GameManager.h>

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
}

void UIManager::cleanup()
{
	cout << "UIManager cleanup method called" << endl; // Output a message to the console for debugging purposes
	// Cleanup UI-specific resources here
}

void UIManager::update()
{
	//cout << "UIManager update method called" << endl; // Output a message to the console for debugging purposes
}

void UIManager::render(RenderWindow& window)
{
	//cout << "UIManager render method called" << endl; // Output a message to the console for debugging purposes
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