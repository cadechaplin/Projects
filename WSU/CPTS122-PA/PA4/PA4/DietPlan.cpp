#include "DietPlan.hpp"

//dietPlan constructors 
DietPlan::DietPlan() {
	goal = 0;
	name = "blank";
	date = "blank";



}

DietPlan::DietPlan(int goal, string name, string date) {
	
	setGoal(goal);
	setName(name);
	setDate(date);


}

//dietPlan copy constructors
DietPlan& DietPlan::operator= (DietPlan& rhs) {

	if (this != &rhs) // checking for self-assignment
	{
		goal = rhs.goal;
		name = rhs.name;
		date = rhs.date;
	}

	return *this;


}

//dietPlan getters
int DietPlan::getGoal() {

	return goal;
}
string DietPlan::getName() {



	return name;

}

string DietPlan::getDate() {



	return date;

}

//dietPlan setters
void DietPlan::setGoal(int newGoal) {
	goal = newGoal;


}

void DietPlan::setGoal(string newGoal) {
	goal = atoi(newGoal.c_str());


}



void DietPlan::setName(string newName) {
	name = newName;

}

void DietPlan::setDate(string newDate) {
	date = newDate;

}



std::ifstream& operator>> (std::ifstream& lhs, DietPlan& rhs) {
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

std::ofstream& operator<< (std::ofstream& lhs, DietPlan& rhs) {
	
	lhs << rhs.getName() << "\n" << rhs.getGoal() << "\n" << rhs.getDate() << "\n" << "\n";


	return lhs;

}

ostream& operator<< (ostream& lhs, DietPlan& rhs) {


	lhs << rhs.getName() << "\n" << rhs.getGoal() << "\n" << rhs.getDate() << "\n" << "\n";


	return lhs;


}