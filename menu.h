#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

//this is the main menu of the game, all couts and choices are made through this class
class Menu {
private:
	int foodtype; //used to store the food type choice. will pass this to the animals in the zoo class
public:
	int start(); //used to start the game
	void Aprices(); //displays the prices of the animals 
	int buy(); //asks for choice of animal to buy, returns the type 1)SL, 2)T, 3)BB.
	int foodChoice(); //ask what type of food they want to buy 
	int getfoodtype();// used to get the type of food choosen 
	int contGame(); //ask if they want to quit or keep playing 

};
#endif // !MENU_H

