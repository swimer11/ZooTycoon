#include "food.h"

using namespace std;

Food::Food() {
	this->food_cost = 80;
	this->tmp = 0;
	this->mult = 1;
	srand(time(NULL));
}

void Food::setfoodcost() {
	tmp = food_cost;
	food_cost = (rand() % 41 + 80) /100 * tmp;
}

double Food::getfoodcost(int type) {//0 cheap, 1 regular, 2 premium
	int i = 0;
	if (type == 1) {
		return ((food_cost / 2)*mult);
	}
	else if (type == 2) {
		return((food_cost)*mult);
	}
	else if (type == 3) {
		return((food_cost* mult)*2);
	}
}
