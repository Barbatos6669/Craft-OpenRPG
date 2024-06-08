#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include <SFML/System/Clock.hpp>

using namespace sf;

class GameClock
{
	public:
	GameClock(); // Constructor
	float getElapsedTime() const; // Get the elapsed time since the clock was started
	void restart(); // Restart the clock

	private:
	Clock m_clock; // The SFML clock object
};

#endif // GAMECLOCK_H
