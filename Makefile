#Makefile

CC= g++ -g -std=c++11
exe_file = ZooTycoon 
$(exe_file): driver.o animal.o bank.o Bear.o sealion.o tiger.o food.o menu.o zoo.o
	$(CC) driver.o animal.o bank.o Bear.o sealion.o tiger.o food.o menu.o zoo.o -o $(exe_file)
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
menu.o: menu.cpp
	$(CC) -c menu.cpp
Bear.o: Bear.cpp
	$(CC) -c Bear.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
bank.o: bank.cpp
	$(CC) -c bank.cpp
food.o: food.cpp
	$(CC) -c food.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)

