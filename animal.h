//function def. for the animal class, needs the food.cpp to run
#ifndef ANIMAL_H
#define ANIMAL_H


#include "food.h"

using namespace std;

class Animal {
   protected: 
      string name;
      int age;
      int bpb; //babies per birth
      double rev; //revenue made for this animal
      int animal_cost;
      double rev_p; //% used to claculate rev, used in mothly_rev(), overriden by each animal
   public:
      Animal();

      int getcost();

      bool isbaby();
      bool isadult();

      void setbpd(int);
      int getbpb();

      double monthly_rev();
    
      string getname();
      void setname(string);

      void defineAge(int);
      void setage();
      int getage();
};

#endif
