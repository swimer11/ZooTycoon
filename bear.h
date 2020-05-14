#ifndef BEAR_H
#define BEAR_H

#include "animal.h"

using namespace std;

class Bear : public Animal, public Food {
public:
	Bear();
};

#endif // !BEAR_H

