#ifndef BEAR_H
#define BEAR_H

#include "animal.h"
//this is the bear class for the zoo, only a contructor all other functions are inherited
using namespace std;

class Bear : public Animal, public Food {
public:
	Bear();
};

#endif // !BEAR_H

