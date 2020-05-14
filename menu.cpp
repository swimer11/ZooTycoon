//this is the menus that are in the game, there is the starting, animal prices, buying, food type, and continue game menus
#include "menu.h"

using namespace std;

//used to start the game and give an option to quit
int Menu::start() {
	int choice = 0;

	cout << "Welcome to Zoo Tycoon! Would you like to: \n 1) Play The Game? \n 2) Quit?\n";
	cin >> choice;
	return choice;
}

//used to display the cost of each animal
void Menu::Aprices() {
	cout << "1) One Sea Lion cost $800 \n";
	cout << "2) One Tiger Cost: $15,000 \n";
	cout << "3) One Black Bear Cost: $6,00 \n";
}

//used to buy a new animal, returns 1-3 for the animals and 0 if they don't buy a animal.
int Menu::buy() {
	int choice = 0;
	cout << "Hurrah! The wanding traveler Phillip has arrived. He has goods if you have coin!\n";
	cout << "Phillip: Would you like to buy a new animal? \n 1) yes? \n 2) no? \n";
	cin >> choice;
	if (choice == 2) {
		cout << "Okay. I will return next month if you change your mind.\n";
		cout << "Phillip leaves with a tear in the corner of his eye.\n";
		return 0;
	}
	else {
		cout << "Hurrah! I have 3 types of animals to choose from. Which type would you like?\n";
		Aprices();
		cin >> choice;
		cout << "Hurrah! An exilent choice. I will deiver it at once. \n";
		cout << "Phillip leaves\n ";
		return choice;
	}
}

//used to choose the type of food
int Menu::foodChoice() {
	cout << "Hey Boss? The animals are starting to get low on food. \nJust wanted to know what type you wanted me to buy.\n \n";
	cout << "1) Your first choice is the offbrand cheap stuff. \n Half the price as the regular food, and gets the job done with with some mystery ingredients, \nbut the animals are more likely to get sick.\n\n";
	cout << "2) Your second choice is the generic regular food. \n It's generic, nothing bad or special about it. \n\n";
	cout << "3) Your third choice is the good stuff. Prime choice cuts, whole grains, Premium food.\n Runs at twice the cost of the regular food. \n\n ";
	cout << "What will it be boss? \n";
	cin >> foodtype;

	cout << "gotcha I order that right away. \n";

	return foodtype;
}

//used to get the type of food in zoo class
int Menu::getfoodtype() {
	return foodtype;
}

//used to stop playing after each month
int Menu::contGame() {
	int choice = 0;
	cout << "Hey boss. Would you like to continue on to next month? \n 1) Keep playing? \n 2) Quit playing?\n ";
	cin >> choice;
	return choice;
}
