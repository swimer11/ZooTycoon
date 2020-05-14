//def. for the animal class functions
#include "animal.h"

using namespace std;

//constuctor
Animal::Animal(){
   this->name= "";
   this->age= 0;
   this->bpb= 0;
   this->rev=0;
   this->rev_p = .1;
   this->animal_cost=0;
   return;
}

//checks if it is a baby
bool Animal::isbaby(){
   if(age<6){
      return true;
   }
   else
      return false;
}

//checks if it is an adult
bool Animal::isadult(){
   if(age>=48){
      return true;
   }
   else
      return false;
}

//set the birth rate of the animal
void Animal::setbpd(int tmp){
   bpb = tmp;
}

//gets the birth rate of the animal 
int Animal::getbpb(){
   return bpb;
}

//give rev of this animal, if baby doubles it
double Animal::monthly_rev() {
    rev = animal_cost * rev_p;
    if (isbaby()) {
        rev *= 2;
    }
    return rev;
}

//gets the name
string Animal::getname() {
    return name;
}

//sets the name to what tmp is
void Animal::setname(string tmp) {
    name = tmp;
}
//used to set the age to a defind number
void Animal::defineAge(int tmp) {
    age = tmp;
}

//adds one month to the age
void Animal::setage() {
    age++;
}
//used to get the age of an animal 
int Animal::getage() {
    return age;
}
//used to get the cost of an animal
int Animal::getcost() {
    return animal_cost;
}
