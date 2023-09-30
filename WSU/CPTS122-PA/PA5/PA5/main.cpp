
#include "test.h"
#include "Program.h"

int main(void) {//gives choice to run test or to run program, easily removable test files

	
	int choice = 0;
	cout << "Run Normal(1)\nRun Tests(2)\n";
	cin >> choice;
	if (choice == 1) {//run program 

		int time = 0;
		cout << "Enter time in minutes:\n";
		cin >> time;
		program(time);

	}
	if (choice == 2) {//run tests
		test sample;
		sample.testWrapper();
	
	
	}






	return 0;

}