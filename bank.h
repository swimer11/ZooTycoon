//this is all the functions and values needed for the money part of the zoo
//iomanip is only used for displaying the values of the account
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
