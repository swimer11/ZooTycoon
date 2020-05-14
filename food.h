#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Food {
protected:
	double food_cost;//cost for the food 
	double tmp;
	int mult; //food cost multiplier
public:
	Food();
	
	void setfoodcost(); 
	double getfoodcost(int); //ask the type in here
	
};
#endif