#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <HealthBar.h>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Player
{
	public:
	enum class PlayerState
	{
		Idle,
		WalkUp,
		WalkDown,
		WalkLeft,
		WalkRight,
		slashUp,
		slashDown,
		slashLeft,
		slashRight,

		Dead
	};

	Player();
	~Player();

	void initialize();
	void cleanup();

	void startPlayer();
	void pausePlayer();
	void resumePlayer();
	void endPlayer();

	void handleEvents();
	void animatePlayer();
	void update();
	void render(RenderWindow& window);

	void savePlayer();
	void loadPlayer();

	PlayerState getPlayerState() const;
	void setPlayerState(PlayerState playerState);

	int getHealth() const;
	int setHealth(int health);
	void takeDamage(int damage);

	private:
	PlayerState currentPlayerState;
	RectangleShape playerShape;
	float speed;

	vector<Sprite> spriteLayers;
	vector<Texture> textures;
	vector<int> framesPerRow;

	int health;
	int maxHealth;
	int mana;
	int experience;
	int level;
	int gold;

	int frameWidth; // The width of each frame in the sprite sheet
	int frameHeight; // The height of each frame in the sprite sheet

	int currentFrame; // The current frame number
	int totalFrames; // The total number of frames in the sprite sheet
	int currentRow; // The current row number
	Clock animationClock; // The clock used for animation
	float frameDuration; // The duration of each frame in seconds
};

// Inline method implementations
inline Player::PlayerState Player::getPlayerState() const
{
	return currentPlayerState;
}

inline void Player::setPlayerState(PlayerState playerState)
{
	currentPlayerState = playerState;
}

inline void Player::takeDamage(int damage)
{
}
