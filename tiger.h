//this is the tiger class for the zoo, only a constructor all other functions are inherited
#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

using namespace std;

class Tiger : public Animal, public Food {
public:
	Tiger();
};

#endif // !TIGER_H
