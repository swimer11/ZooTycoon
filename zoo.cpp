#include "zoo.h"

using namespace std;

Zoo::Zoo() {
	//random number to choose, this changes if more then 10 is added then it is 20, 30,.., etc
	this->maxSlions = 10;
	this->maxBears = 10;
	this->maxTigers = 10;

	this->numBears = 0;
	this->numSealions = 0;
	this->numTigers = 0;

	Spin = new SeaLion[maxSlions];
	Tpin = new Tiger[maxTigers];
	Bpin = new Bear[maxBears];
}

//used to check if the input is between 1 and to
bool Zoo::checkint(int tmp) {
	if (tmp == 1 || tmp == 2) {
		return true;
	}
	return false;
}

//starts zoo and then ask is the user wants to buy some animals, lets the user buy 1-2 of one type
void Zoo::makezoo() {
	int startingT = 0, //starting number of animals chosen between 1 or 2
		startingS = 0,
		startingB = 0,
		totalT = 0,  //total cost for each type of animal
		totalS = 0,
		totalB = 0;

	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Congratulations! Today is the big day. You have $" << acount.getbalance() << "\n";
	cout << "The only thing left to do is buy some animals. \n";
	cout << "But where can we do that?\n";
	
	buyAnimal();


	cout << "\nWell now that all of that is done your remaining balance is: $" << acount.getbalance() << "\n \n";
}

void Zoo::gameplay() {
	int choice,
		mon_num =0; //use to track ther months

	makezoo();
	int nextmonth = 1;

	while (nextmonth == 1 && acount.getbalance() > 0) {
		//start all ints needed to deal with animals
		int AllAnimals,
			foodType,
			BabyS = 0,
			BabyT = 0,
			BabyB = 0,
			KidS = 0,
			KidT = 0,
			KidB = 0,
			AdultS = 0,
			AdultT = 0,
			AdultB = 0;
		
		//doubles for revenue made by random and animals started
		double Bonus_rev,
			ProfitS,
			ProfitT,
			ProfitB,
			P_total;

		mon_num++;
		cout << "\n\n\nMonths that the zoo has been open: " << mon_num << "\n \n";
		cout << "Current Balance: $" << acount.getbalance() << "\n \n";

		cout << "Current amount and type of animals: \n";

		//start with sea lions
		ageAnimal(Spin, numSealions, AdultS, BabyS, KidS);
		cout << "You have " << numSealions << " number of Sea lions.\n";
		//cout << "Adult Sea Lions: " << AdultS << "\n";
		//cout << "Child Sea Lions: " << KidS << "\n";
		//cout << "Baby Sea Lions: " << BabyS << "\n";

		//then all tigers
		ageAnimal(Tpin, numTigers, AdultT, BabyT, KidT);
		cout << "You have " << numTigers << " number of Tigers.\n";
		//cout << "Adult Tigers: " << AdultT << "\n";
		//cout << "Child Tigers: " << KidT << "\n";
		//cout << "Baby Tigers: " << BabyT << "\n";

		//finally the Black Bears
		ageAnimal(Bpin, numBears, AdultB, BabyB, KidB);
		cout << "You have " << numBears << " number of Black Bears.\n\n";
		//cout << "Adult Black Bears: " << AdultB << "\n";
		//cout << "Child Black Bears: " << KidB << "\n";
		//cout << "Baby Black Bears: " << BabyB << "\n \n \n";

		AllAnimals = numBears + numSealions + numTigers;
		if (AllAnimals == 0) {
			cout << "Hey boss, you don't have any animals in the zoo. You should talk to Phillip. \n";
			buyAnimal();
		}
		else { //random event happen here
			foodType = feedingTime();
			Bonus_rev = randomEvents(foodType); 

			//calc profit
			cout << "\n Hey boss, here is the profits for the month: \n";
			cout << fixed << showpoint << setprecision(2);
			
			//start with Sea lions
			ProfitS = profits(Spin, numSealions);
			cout << "The Sea lion exhibit made: $" << ProfitS << " this month\n";

			//then Tigers
			ProfitT = profits(Tpin, numTigers);
			cout << "The Tiger exhibit made: $" << ProfitT << " this month\n";

			//finally bears
			ProfitB = profits(Bpin, numBears);
			cout << "The Black Bear exhibit made: $" << ProfitB << " this month\n";

			if (Bonus_rev != 0) {
				cout << "Hey boss, we got a bonus for a random event. You made: $" << Bonus_rev << " from that event\n";
			}

			//add all profits to the bank
			P_total = ProfitB + ProfitS + ProfitT + Bonus_rev;
			cout << "\nAnd that brings the total to..... $" << P_total << ". Wow guess that's why they call you the boss. \n\n\n";
			acount.depoist(P_total);

			//buy some animals now
			if (acount.getbalance() > 0) {
				buyAnimal();
			}
			//check is they lost due to no money
			if (acount.getbalance() <= 0) {
				cout << "OH NO boss, we're out of money :( . Guess we have to shut down... \n The Game is over. \n \n";
			}
			else {
				cout << "\n Okay boss we currently have: $" << acount.getbalance() << "\n \n";
				nextmonth = mainMenu.contGame();
			}
		}
	}
}

//used to buy a new 4 year old animal
void Zoo::buyAnimal() {
	int cost = 0;
	int choice = 0;
	int tmp = mainMenu.buy();
	//start with sea lion
	if (tmp == 1) {
		cout << " \n Delivery Guy: \n Hey there Phillip sent me with two Sea Lions. Is that how many you wanted? \n 1) no \n 2) yes\n";
		cin >> choice;
		for (int i = 0; i < choice; i++) {
			cost += Spin->getcost();
		}
		cout << "Okay that is going to cost: $" << cost << "\n";
		addSeaLion(choice, 50); //starts off at 4 years old
		acount.withdraw(cost);
	}
	//then Tiger
	else if (tmp == 2) {
		cout << " \n Delivery Guy: \n Hey there Phillip sent me with two Tigers. Is that how many you wanted? \n 1) no \n 2) yes\n";
		cin >> choice;
		for (int i = 0; i < choice; i++) {
			cost += Tpin->getcost();
		}
		cout << "Okay that is going to cost: $" << cost << "\n";
		addTiger(choice, 50); //starts off at 4 years old
		acount.withdraw(cost);
	}
	//finally Bears
	else if (tmp == 3) {
		cout << " \n Delivery Guy: \n Hey there Phillip sent me with two Black Bears. Is that how many you wanted? \n 1) no \n 2) yes\n";
		cin >> choice;
		for (int i = 0; i < choice; i++) {
			cost += Bpin->getcost();
		}
		cout << "Okay that is going to cost: $" << cost <<"\n";
		addBear(choice, 50); //starts off at 4 years old
		acount.withdraw(cost);
	}
	//order nothing
	else {
		cout << " \n You didn't buy any animals this month.\n ";
	}
}

//used to get the profits from an array of animals
double Zoo::profits(Animal* animals, int numanimals) {
	double one_animal,
		total = 0;
	for (int i = 0; i < numanimals; i++) {
		one_animal = animals->monthly_rev();
		if (animals->isbaby()) {
			one_animal *= 2;
		}
		total += one_animal;
	}
	return total;
}

//used to determin the random event that will happen. It then calls that function to cause the event.
double Zoo::randomEvents(int foodtype) {
	int chance;
	double bonus_rev = 0;
	chance = rand() % 24 + 1;

	if (foodtype == 0) { //cheap food
		if (chance <= 12) { //if in this range a animal gets sick 
			sickness();
		}
		else if (chance <= 16) { //if in this range the park gets a boom in visitors 
			bonus_rev = AttendanceBoom();
		}
		else if (chance <= 20) { //if in this range a baby is born
			babyBorn();
		}
		else //if in this range then nothing happens
		{
			noevent();
		}
	}
	else if (foodtype == 1) { //regular food
		if (chance <= 6) { //if in this range a animal gets sick 
			sickness();
		}
		else if (chance <= 12) { //if in this range the park gets a boom in visitors 
			bonus_rev = AttendanceBoom();
		}
		else if (chance <= 18) { //if in this range a baby is born
			babyBorn();
		}
		else //if in this range then nothing happens
		{
			noevent();
		}
	}
	else if (foodtype == 3) { //premium food
		if (chance <= 3) { //if in this range a animal gets sick 
			sickness();
		}
		else if (chance <= 10) { //if in this range the park gets a boom in visitors 
			bonus_rev = AttendanceBoom();
		}
		else if (chance <= 17) { //if in this range a baby is born
			babyBorn();
		}
		else //if in this range then nothing happens
		{
			noevent();
		}
	}
	return bonus_rev;
}

//used to make one animal in the zoo sick 
void Zoo::sickness() {
	int tmp = 0;
	int j = 0;
	double bill = 0;
	string name;
	tmp = rand() % 3 + 1;

	//start with sea lions
	if (tmp == 1 && numSealions > 0) {
		name = "Sea Lion";
		j = rand() % numSealions;
		bill = Spin[j].getcost();
		if (Spin[j].isbaby()) { //check if it's a baby
			bill *= 2;
			name = "Baby Sea Lion";
		}
	}
	//then Tigers
	else if (tmp == 2 && numTigers > 0) {
		name = "Tiger";
		j = rand() % numTigers;
		bill = Tpin[j].getcost();
		if (Tpin[j].isbaby()) { //check if it's a baby
			bill *= 2;
			name = "Baby Tiger";
		}
	}
	//then Bear
	else if (tmp == 3 && numBears > 0) {
		name = "Black Bear";
		j = rand() % numBears;
		bill = Bpin[j].getcost();
		if (Bpin[j].isbaby()) { //check if it's a baby
			bill *= 2;
			name = "Baby Black Bear";
		}
	}
	//if the choice doesn't exist in the zoo then one that is there will be chosen 
	else if (numSealions > 0)
	{
		name = "Sea Lion";
		j = rand() % numSealions;
		bill = Spin[j].getcost();
		if (Spin[j].isbaby()) { //check if it's a baby
			bill *= 2;
			name = "Baby Sea Lion";
		}
	}
	else if (numTigers > 0)
	{
		name = "Tiger";
		j = rand() % numTigers;
		bill = Tpin[j].getcost();
		if (Tpin[j].isbaby()) { //check if it's a baby
			bill *= 2;
			name = "Baby Tiger";

		}
	}
	else if (numBears > 0)
	{
		name = "Black Bear";
		j = rand() % numBears;
		bill = Bpin[j].getcost();
		if (Bpin[j].isbaby()) { //check if it's a baby
			bill *= 2;
			name = "Baby Black Bear";
		}

		cout << "Hey boss, it seems like a " << name << " has gotten sick. \n It's going to cost us: $" << bill << "\n";
		acount.withdraw(bill);

	}
}

//used to give the bonus for the attendance Boom event
double Zoo::AttendanceBoom() {
	int bonus = 0;
	double total = 0;

	bonus = rand() % (400 - 150 + 1) + 150; //bonus per sea lion

	for (int i = 0; i < numSealions; i++) {
		total += bonus;
	}

	cout << "Hey boss, there was a boom in zoo attendance last month.\n You earned an extra: $" << bonus << " per Sea lion.\n";
	cout << "That means we got a bonus of.... \n Wow $" << total << ", Nice work Boss.\n";
	return total;
}

//used to feed the animals
int Zoo::feedingTime() {
	int choice;
	double FoodS = 0,
		FoodT = 0,
		FoodB = 0,
		total;
	
	choice = mainMenu.foodChoice();

	//calc cost for all animals
	//start with Sea lions
	for (int i = 0; i < numSealions; i++) {
		FoodS += Spin->getfoodcost(choice);
	}
		cout << "\nSea lion food is going to cost: $" << FoodS << "\n";
	
	//then Tigers
		for (int i = 0; i < numTigers; i++) {
			FoodT += Tpin->getfoodcost(choice);
		}
		cout << "\nTiger food is going to cost: $" << FoodT << "\n";
	
	//finally Bears
		for (int i = 0; i < numBears; i++) {
			FoodB += Bpin->getfoodcost(choice);
		}
		cout << "\nBlack Bear food is going to cost: $" << FoodB << "\n";
	

	//find the total and withdraw it
	total = FoodB + FoodS + FoodT;
	cout << "The total cost of feeding everyone is: $" << total << "\n\n";
	acount.withdraw(total);

	return choice;

}

void Zoo::ageAnimal(Animal* animals, int numA, int& adults, int& babies, int& kids) {
	for (int i = 0; i < numA; i++) {
		animals[i].setage();

		if (animals[i].isadult()) {
			adults++;
		}
		else if(animals[i].isbaby()){
			babies++;
		}
		else {
			kids++;
		}

	}
}

void Zoo::babyBorn() {
	bool AdultS = false,
		AdultT = false,
		AdultB = false;

	int choosen = 0,
		BPB = 0;

	string name;

	//choose the species
	choosen = rand() % 3 + 1; // 1s, 2t, 3b

	//check if there is an adult to give birth
	for (int i = 0; i < numSealions; i++) {
		if (Spin[i].isadult()) {
			AdultS = true;
		}
	}
	
	//check for tigers
	for (int i = 0; i < numTigers; i++) {
		if (Tpin[i].isadult()) {
			AdultT = true;
		}
	}

	//check for Bears
	for (int i = 0; i < numBears; i++) {
		if (Bpin[i].isadult()) {
			AdultB = true;
		}
	}

	//sea lion give birth
	if (AdultB || AdultS || AdultT) {
		if (choosen == 1 && AdultS) {
			BPB = Spin->getbpb();
			cout << "Hey boss! A Sea Lion just had " << BPB << " babies! \n";
			addSeaLion(BPB, 0); //age is 0 for babies
		}

		//Tiger gives birth
		else if (choosen == 2 && AdultT) {
			BPB = Tpin->getbpb();
			cout << "Hey boss! A Tiger just had " << BPB << " babies! \n";
			addTiger(BPB, 0); //age is 0 for babies
		}

		//Bear gives birth
		else if (choosen == 1 && AdultB) {
			BPB = Bpin->getbpb();
			cout << "Hey boss! A Bear just had " << BPB << " babies! \n";
			addBear(BPB, 0); //age is 0 for babies
		}
		//if choosen doesn't have any adults then one is choosen here, same as sickness
		//sea lion
		else if ( AdultS) {
			BPB = Spin->getbpb();
			cout << "Hey boss! A Sea Lion just had " << BPB << " babies! \n";
			addSeaLion(BPB, 0); //age is 0 for babies
		}//tiger
		else if ( AdultT) {
			BPB = Tpin->getbpb();
			cout << "Hey boss! A Tiger just had " << BPB << " babies! \n";
			addTiger(BPB, 0); //age is 0 for babies
		}//bears
		else if (AdultB) {
			BPB = Bpin->getbpb();
			cout << "Hey boss! A Bear just had " << BPB << " babies! \n";
			addBear(BPB, 0); //age is 0 for babies
		}
	}
}


//used when no random event happens
void Zoo::noevent() {
	cout << "Hey Boss, this month has been uneventful \n Nothing special has happened\n";
}

//used to add a sea lion to the exhibit 
void Zoo::addSeaLion(int numAdded, int age){
	int AgeS;
	SeaLion* tmp;

	numSealions += numAdded;

	if (numSealions >= maxSlions){
		maxSlions *= 2; //increase size if full
		tmp = new SeaLion[maxSlions];

		for (int i = 0; i < numSealions; i++){
			//adding the new Sea Lion if no space
			if (i > ((numSealions - 1) - numAdded)){
				tmp[i].defineAge(age);
			}

			//Copying ages of sealions in old array into new array
			else{
				AgeS = Spin[i].getage();
				tmp[i].defineAge(AgeS);
			}
		}

		delete[] Spin;

		//adding new array to the original
		Spin = tmp;
	}

	//Adding new Sea lions if there is still room
	else{
		for (int i = 0; i < numSealions; i++){
			if (i > ((numSealions - 1) - numAdded)){
				Spin[i].defineAge(age);
			}
		}
	}
}
//used to add a Tiger to the exhibit 
void Zoo::addTiger(const int numAdded, const int age) {
	int AgeT;
	Tiger* tmp;

	numTigers += numAdded;

	if (numTigers >= maxTigers) {
		maxTigers *= 2;
		tmp = new Tiger[maxTigers];

		for (int i = 0; i < numTigers; i++) {
			//adding the new Tiger if no space
			if (i > ((numTigers - 1) - numAdded)) {
				tmp[i].defineAge(age);
			}

			//Copying ages of Tiger in old array into new array
			else {
				AgeT = Tpin[i].getage();
				tmp[i].defineAge(AgeT);
			}
		}

		delete[] Tpin;

		//adding new array to the original
		Tpin = tmp;
	}

	//Adding new Tiger if there is still room
	else {
		for (int i = 0; i < numTigers; i++) {
			if (i > ((numTigers - 1) - numAdded)) {
				Tpin[i].defineAge(age);
			}
		}
	}
}
//used to add a Bear to the exhibit 
void Zoo::addBear(int numAdded, int age) {
	int AgeB;
	Bear* tmp;

	numBears += numAdded;

	if (numBears >= maxBears) {
		maxBears *= 2;
		tmp = new Bear[maxBears];

		for (int i = 0; i < numBears; i++) {
			//adding the new Bear if no space
			if (i > ((numBears - 1) - numAdded)) {
				tmp[i].defineAge(age);
			}

			//Copying ages of Bear in old array into new array
			else {
				AgeB = Bpin[i].getage();
				tmp[i].defineAge(AgeB);
			}
		}

		delete[] Bpin;

		//adding new array to the original
		Bpin = tmp;
	}

	//Adding new Tiger if there is still room
	else {
		for (int i = 0; i < numBears; i++) {
			if (i > ((numBears - 1) - numAdded)) {
				Bpin[i].defineAge(age);
			}
		}
	}
}

Zoo::~Zoo() {
	delete[] Spin;
	delete[] Bpin;
	delete[] Tpin;
}
