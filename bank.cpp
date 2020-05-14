//this is the function def. for all bank.cpp functions
#include "bank.h"

using namespace std;

//starts the account with $100,000
Bank::Bank() {
	this->balance = 100000;
}

//used whenever money is added
void Bank::withdraw(double tmp) {
	balance -= tmp;

	cout << fixed << showpoint << setprecision(2);
	cout << "$" << tmp << " was taken from your account. \nNew Balance: $" << getbalance() << "\n";
}

//used whenever money is taken 
void Bank::depoist(double tmp) {
	balance += tmp;

	cout << fixed << showpoint << setprecision(2);
	cout << "$" << tmp << " was added to your account. \nNew Balance: $" << getbalance() << "\n";
}

//used to get the balance
double Bank::getbalance() {
	return balance;
}
