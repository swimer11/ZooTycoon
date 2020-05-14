//this is the zoo class, all other classes come together in this one class
#ifndef ZOO_H
#define ZOO_H

#include "sealion.h"
#include "bear.h"
#include "tiger.h"
#include "bank.h"
#include "menu.h"

using namespace std;

class Zoo {
private:

	//sets a limit for the amount of each animal the zoo can hold
	int maxSlions;
	int maxTigers;
	int maxBears;

	//number of each animal in the zoo 
	int numSealions;
	int numTigers;
	int numBears;

	//dynamic arrays that will hold the animals
	SeaLion* Spin;
	Bear* Bpin;
	Tiger* Tpin;

	//classes def.
	Bank acount;
	Menu mainMenu;

	void makezoo(); //sets up the zoo 
	void ageAnimal(Animal*, int, int&, int&, int&); //adds one month to each animal each turn
	int feedingTime(); //used to feed the animals and get the type of food choosen back 
	void buyAnimal(); //used to buy up to two animals per month
	double profits(Animal*, int); //used to calc profit

	//random events
	double randomEvents(int);
	void sickness();
	double AttendanceBoom();
	void babyBorn();
	void noevent();

	//adding animals when bought or born
	void addSeaLion(int, int);
	void addTiger(int, int);
	void addBear(int, int);

public:
	Zoo();
	~Zoo();

	bool checkint(int);
	void gameplay();

};
#endif // !ZOO_H
