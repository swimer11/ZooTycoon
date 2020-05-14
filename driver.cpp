/******************************************************
 * ** Program: zoo_tycoon.cpp
 * ** Author: Tyler Cohade
 * ** Date: 05/08/2020
 * ** Description: This is a text based game of Zoo Tycoon, in this game you have to make profit for a zoo that you 
 * populate with 3 differetn types of animals(sea lions, tigers, bears). This must be run with the 9 other .cpp files for this to work.
 * ** Input:N/a
 * ** Output:N/a
 * ******************************************************/
#include "zoo.h"

using namespace std;

int main() {

	Menu mainMenu;

	int tmp = 0;

	tmp = mainMenu.start();

	while (tmp == 1) {
		Zoo* theZoo = new Zoo;

		theZoo->gameplay();

		cout << "\n Would you like to play again? \n 1) Yes\n 2) No\n";
		cin >> tmp;
		delete theZoo;
	}
	cout << "Come Back Soon! \n";
	return 0;
}
