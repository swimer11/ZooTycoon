#ifndef SEALION_H
#define SEALION_H

#include "animal.h"
//this is the sea lion class, it needs to run with the animal and food class.
using namespace std;

class SeaLion : public Animal, public Food {
public:
	SeaLion();
};

#endif // !SEALION_H
