#include "ExercisePlan.hpp"
//exercisePlan construtors

ExercisePlan::ExercisePlan() {
	goal = 0;
	name = "blank";
	date = "blank";



}

ExercisePlan::ExercisePlan(int goal, string name, string date) {
	goal = 0;
	name = "blank";
	date = "blank";
	setGoal(goal);
	setName(name);
	setDate(date);


}
//exercisePlan copy constructors
ExercisePlan& ExercisePlan::operator= (ExercisePlan& rhs) {

	if (this != &rhs) // checking for self-assignment
	{
		goal = rhs.goal;
		name = rhs.name;
		date = rhs.date;
	}

	return *this;


}

//exercisePlan getters
int ExercisePlan::getGoal() {

	return goal;
}
string ExercisePlan::getName() {



	return name;

}

string ExercisePlan::getDate() {



	return date;

}



//exercisePlan setters
void ExercisePlan::setGoal(int newGoal) {
	goal = newGoal;


}

void ExercisePlan::setGoal(string newGoal) {
	goal = atoi(newGoal.c_str());


}


void ExercisePlan::setName(string newName) {
	name = newName;

}

void ExercisePlan::setDate(string newDate) {
	date = newDate;

}



std::ifstream& operator>> (std::ifstream& lhs, ExercisePlan& rhs) {
	string input;

	getline(lhs, input);
	rhs.setName(input);
	getline(lhs, input);
	rhs.setGoal(input);
	getline(lhs, input);
	rhs.setDate(input);
	getline(lhs, input);
	return lhs;



}

std::ofstream& operator<< (std::ofstream& lhs, ExercisePlan& rhs) {

	lhs << rhs.getName() << "\n" << rhs.getGoal() << "\n" << rhs.getDate() << "\n" << "\n";


	return lhs;

}

ostream& operator<< (ostream& lhs, ExercisePlan& rhs) {


	lhs << rhs.getName() << "\n" << rhs.getGoal() << "\n" << rhs.getDate() << "\n" << "\n";


	return lhs;


}