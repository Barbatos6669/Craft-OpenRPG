#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <vector>
#include <string>

using namespace sf;
using namespace std;

class UIManager
{
	public:

	enum class UIState
	{
		MainMenu,
		Playing,
		Paused,
		GameOver
	};
	// The constructor initializes the class, and the destructor ensures cleanup when the class instance is
	UIManager(); // Constructor
	~UIManager(); // Destructor

	void initialize(); // This method is intended to set up the game, such as initializing game systems and resources.
	void cleanup(); // This method handles the cleanup of resources when the game ends.

	void update(); // Update the game state
	void render(RenderWindow& window); // Render the game state

	void setUIState(UIState uiState); // Set the game state
	UIState getUIState() const; // Get the game state

	private:

	UIState currentUIState; // The current state of the UI
	Font font; // Font for text
	std::vector<Text> texts; // Container for UI texts

	void setupMainMenu(); // Setup main menu UI components
	void setupPlayingUI(); // Setup playing UI components
	void setupPausedUI(); // Setup paused UI components
	void setupGameOverUI(); // Setup game over UI components
};

// Inline method implementations
inline UIManager::UIState UIManager::getUIState() const
{
	return currentUIState;
}

inline void UIManager::setUIState(UIState state)
{
	currentUIState = state;
}