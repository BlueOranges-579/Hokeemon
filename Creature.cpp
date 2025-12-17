#include "Creature.h"
#include <iostream>
#include <random>


// Default Constructor
Creature::Creature(){
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,6);
	this->mBoredom = distribution(generator);
	this->mHunger = distribution(generator);
	this->mName = "";

}

// Main loop of the game
void Creature::StartGame(){
	bool quit {false};
	int choice {1};
	Intro();

	while(!quit){
		choice = Menu();

		switch(choice){
		case 1: Listen();
				quit = DeathCheck();
			break;
		case 2: Play();
				quit = DeathCheck();
			break;
		case 3: Feed();
				quit = DeathCheck();
			break;
		case 4: std::cout << "Quitting...." << std::endl; 
				std::cout << "Thanks for playing :)!" << std::endl;
				quit = true;
				break;
		}	
		PassTime(); // Increase the boredom and hunger of the creature
	}
}

// Display the intro and get name of the creature
void Creature::Intro(){
	std::cout << "\t\t\t\t\tWelcome to the Hokeemon World!" << std::endl;
	std::cout << "Play, Feed, and Named your very own digital pet!!" << std::endl;
	std::cout << "Enter a name for your new pet: ";
	std::cin >> mName;
	std::cout << mName << " thanks you for the name!" << std::endl;
	std::cout << std::endl;	
	
}

// Display the main menu
int Creature::Menu(){
	int choice;
	std::cout << "1.Listen\n2.Play\n3.Feed\n4.Quit\n";
	std::cout << "Select an Activity: ";
	std::cin >> choice;

	// Input Validation
	while (choice > 4 || choice < 1) {
		std::cout << "Invalid Input. Try Again." << std::endl;
		std::cin >> choice;
	}
	return choice;
}

// Display the current boredom and hunger of the creature
void Creature::Listen(){
	std::cout << "Hunger: " << mHunger << std::endl;
	std::cout << "Boredom: " << mBoredom << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.get();   // Waits for the user to press Enter
}


// Increase the hunger and boredom of the creature
void Creature::PassTime(){
	mHunger++;
	mBoredom++;

	// Prevent negative numbers
	if(mHunger < 0){
		mHunger = 0;
	}
	if(mBoredom < 0){
		mBoredom = 0;
	}
}


// Play with the creature
void Creature::Play(){
	std::cout << "You have played with " << mName << "!" << std::endl;
	mBoredom -= 4;
}

// Feed the creature
void Creature::Feed(){
	std::cout << "You have fed " << mName << "!" << std::endl;
	mHunger-= 4;
}

// Check if the creature had died of starvation of boredom
bool Creature::DeathCheck(){
	if(mBoredom > 20){
		std::cout << mName << " is on unresponsive catatonin state caused by boredom. You Lose." << std::endl;
		std::cout << "Quitting..." << std::endl;
		std::cout << "Thanks for playing!" << std::endl;
		return true;
	}

	else if(mHunger > 10){
		std::cout << mName << " died of starvation. You Lose." << std::endl;
		std::cout << "Quitting..." << std::endl;
		std::cout << "Thanks for playing!" << std::endl;
		return true;
	}

	else{
		return false;
	}
}