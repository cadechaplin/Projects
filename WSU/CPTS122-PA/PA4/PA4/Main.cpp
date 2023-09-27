
//#include "list.hpp"
#include "FitnessAppWrapper.hpp"


/*
Cade Chaplin 
PA4
10/14/2022

What program does:
Program declares two class types for each diet plans and exercise plans, by declaring them sets the int variables as 0 and string variables as blank.
Program gives the option to load, store, and edit each variable for each day.
There are only 7 days that are usable as there are 7 days in a week. 

*/
int main() {
	int choice = -10;
		DietPlan diet[7];//creates mem for dietplans


	ExercisePlan ex[7];// creates mem for exercise plans

	FitnessAppWrapper app;

	while (choice != 9) {
		choice = app.displayMenu();//displays menu and returns what user wants to do 
	
		switch (choice)
		{
		case 1:
			app.loadWeeklyPlan(diet);//loads from file into class array dietplan
			break;
		case 2:
			app.loadWeeklyPlan(ex);//overload for exercise plans
			break;
		case 3:
			app.storeWeeklyPlan(diet);//puts array back into file
			break;
		case 4:
			app.storeWeeklyPlan(ex);//overload for exercise plans
			break;
		case 5:
			app.displayWeeklyPlan(diet);//shows all plans in array weekly plan from array, not file
			break;
		case 6:
			app.displayWeeklyPlan(ex);//overload for exercise plans
			break;
		case 7:
			app.editWeeklyPlan(diet);//edit a member of class diet 
			break;
		case 8:
			app.editWeeklyPlan(ex);//overload for exercise plans
			break;
		}
	
	
	
	
	
	
	
	
	
	};


	

	

	/*
	for (int i = 0; i < 7; i++)
	{
		diet[i].setGoal(i);



	}
	

	app.loadWeeklyPlan(diet);


	

	app.storeWeeklyPlan(diet);
	app.displayWeeklyPlan(diet);

	app.editWeeklyPlan(diet);

	app.storeWeeklyPlan(diet);
	*/
	/*
	for (int i = 0; i < 7; i++)
	{
		cout << diet[i].getName() << "\n";
	}
	*/
	

	


	
	
	//Node* pMem;
	

}