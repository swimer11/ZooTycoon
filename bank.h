#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <iomanip>


class Bank {
protected:
	double balance; //balance of the zoo
public:
	Bank(); //constructor

	void withdraw(double); //adds money to balance
	void depoist(double); //takes money from balance
	double getbalance(); //returns balance
};
#endif // !BANK_H
