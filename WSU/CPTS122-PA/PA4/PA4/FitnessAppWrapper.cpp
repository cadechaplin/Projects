#include "FitnessAppWrapper.hpp"





void FitnessAppWrapper::loadWeeklyPlan(DietPlan diet[7]) {

	
	std::ifstream inputStream;

	

	inputStream.open("dietPlans.txt", std::ios::in);
	if (inputStream.is_open()) 
	{
	
		
		for (int i = 0; i < 7; i++)
		{
			//inputStream >> diet[i];
			loadDailyPlan(&diet[i], inputStream);
		}
			
	}
	inputStream.close();
}


void FitnessAppWrapper::loadWeeklyPlan(ExercisePlan ex[7]) {


	std::ifstream inputStream;



	inputStream.open("ExPlans.txt", std::ios::in);
	if (inputStream.is_open())
	{


		for (int i = 0; i < 7; i++)
		{
			//inputStream >> diet[i];
			loadDailyPlan(&ex[i], inputStream);
		}

	}
	inputStream.close();
}


void FitnessAppWrapper::loadDailyPlan(DietPlan *diet, std::ifstream &inputStream) {


	inputStream >> *diet;


}
void FitnessAppWrapper::loadDailyPlan(ExercisePlan* diet, std::ifstream& inputStream) {


	inputStream >> *diet;


}

//setters
//void loadDailyPlan();
//void storeWeeklyPlan(ExercisePlan plan);

void FitnessAppWrapper::storeWeeklyPlan(DietPlan plan[7]) {


	
	std::ofstream inputStream;



	inputStream.open("dietPlans.txt", std::ios::out);
	if (inputStream.is_open())
	{


		for (int i = 0; i < 7; i++)
		{
			storeDailyPlan(plan[i], inputStream);



		//	inputStream << plan[i];
		}



	}
	inputStream.close();

}

void FitnessAppWrapper::storeWeeklyPlan(ExercisePlan plan[7]) {



	std::ofstream inputStream;



	inputStream.open("ExPlans.txt", std::ios::out);
	if (inputStream.is_open())
	{


		for (int i = 0; i < 7; i++)
		{
			storeDailyPlan(plan[i], inputStream);



			//	inputStream << plan[i];
		}



	}
	inputStream.close();

}


void FitnessAppWrapper::storeDailyPlan(DietPlan plan, std::ofstream &inputStream) {

	inputStream << plan;

}

void FitnessAppWrapper::storeDailyPlan(ExercisePlan plan, std::ofstream& inputStream) {

	inputStream << plan;

}









void FitnessAppWrapper::displayWeeklyPlan(DietPlan diet[7]) {

	for (int i = 0; i < 7; i++)
	{

		displayDailyPlan(&diet[i]);

	}

}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan diet[7]) {

	for (int i = 0; i < 7; i++)
	{

		displayDailyPlan(&diet[i]);

	}

}


void FitnessAppWrapper::displayDailyPlan(DietPlan diet[1]) {


	cout << *diet;

}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan diet[1]) {


	cout << *diet;

}

int editMenu() {

	cout << "Chose a day to edit: Monday(1), Tueday(2), ect...\n";
	string choice;
	getline(std::cin, choice);
	return atoi(choice.c_str());


}

void FitnessAppWrapper::editWeeklyPlan(DietPlan diet[7]) {

	int i = editMenu();


	editDailyPlan(&diet[i-1]);
	



}


void FitnessAppWrapper::editWeeklyPlan(ExercisePlan diet[7]) {

	int i = editMenu();


	editDailyPlan(&diet[i - 1]);




}


int editMenuItem() {

	cout << "Chose a item to edit: Name(1), Goal(2), Date(3)\n";
	string choice;
	getline(std::cin, choice);
	return atoi(choice.c_str());


}

void FitnessAppWrapper::editDailyPlan(DietPlan diet[1]) {

	int i = editMenuItem();
	string choice;

	if (i == 1)// name
	{
		cout << "enter new name:\n";
		
		getline(std::cin, choice);

		(*diet).setName(choice);

	}

	if (i == 2)// goal
	{
		cout << "enter new goal:\n";

		getline(std::cin, choice);

		(*diet).setGoal(choice);

	}

	if (i == 3)// date
	{
		cout << "enter new date:\n";

		getline(std::cin, choice);

		(*diet).setDate(choice);

	}




}


void FitnessAppWrapper::editDailyPlan(ExercisePlan diet[1]) {

	int i = editMenuItem();
	string choice;

	if (i == 1)// name
	{
		cout << "enter new name:\n";

		getline(std::cin, choice);

		(*diet).setName(choice);

	}

	if (i == 2)// goal
	{
		cout << "enter new goal:\n";

		getline(std::cin, choice);

		(*diet).setGoal(choice);

	}

	if (i == 3)// date
	{
		cout << "enter new date:\n";

		getline(std::cin, choice);

		(*diet).setDate(choice);

	}




}

int FitnessAppWrapper::displayMenu() {
	cout << "Select a choice:\n1. Load weekly diet plan from file.\n2.    Load weekly exercise plan from file.]\n3.    Store weekly diet plan to file.\n4.    Store weekly exercise plan to file.\n5.    Display weekly diet plan to screen.\n6.    Display weekly exercise plan to screen.\n7.    Edit daily diet plan.\n8.    Edit daily exercise plan.\n9.    Exit.\n";
	string choice;
	getline(std::cin, choice);
	return atoi(choice.c_str());

}











































//exercise overloads
//storeDailyPlan ();

//storeWeeklyPlan ();

//displayMenu ();


