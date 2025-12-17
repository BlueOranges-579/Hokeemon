#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature{
private:
	int mHunger;
	int mBoredom;
	std::string mName;
public:
	Creature();
	int Menu();
	void StartGame();
	void Intro();
	void Listen();
	void Play();
	void Feed();
	void PassTime();
	bool DeathCheck();
};

#endif
