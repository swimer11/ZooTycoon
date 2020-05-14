//this is the only function in the sealion class, all others are inharited
#include "sealion.h"

using namespace std;
//constructor for the sea lion class
//overides some varable in the animal class to make it a sea lion
SeaLion::SeaLion() {
	this->rev_p = .2;
	this->animal_cost = 800;
	this->bpb = 1;

}
