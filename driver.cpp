#include "zoo.h"

using namespace std;

int main() {

	Menu mainMenu;

	int tmp = 0;

	tmp = mainMenu.start();

	while (tmp == 1) {
		Zoo* theZoo = new Zoo;

		theZoo->gameplay();

		cout << "\n Would you like to play again? \n 1) Yes\n 2) No\n";
		cin >> tmp;
		delete theZoo;
	}
	cout << "Come Back Soon! \n";
	return 0;
}