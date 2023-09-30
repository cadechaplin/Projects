#include "data.h"

Data::Data(int id, int time, int line) {

	customerNumber = id;
	
		serviceTime = 1 + (rand() % line);
		//cout << serviceTime << "\n";

	totalTime = time + serviceTime;
	//cout << "J: Line:Express Time: " << time << " ID: " << customerNumber << "\n";

};


Data::Data() {

	customerNumber = 0;

	serviceTime = 0;
	//cout << serviceTime << "\n";

	totalTime = 0;
	//cout << "J: Line:Express Time: " << time << " ID: " << customerNumber << "\n";

};

Data Data::operator= (Data rhs) {

	if (this != &rhs) // checking for self-assignment
	{
		customerNumber = rhs.getID();
		serviceTime = rhs.getTime();
		totalTime = rhs.getTotal();



	}

	return *this;


}


void Data::min() {

	serviceTime = serviceTime - 1;




}

int Data::getTime() {
	return serviceTime;

}

int Data::getID() {

	return customerNumber;

}


int Data::getTotal() {

	return totalTime;

}

