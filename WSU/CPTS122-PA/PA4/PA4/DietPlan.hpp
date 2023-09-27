#pragma once
#include "ExercisePlan.hpp"
class DietPlan
{
public:





	//constructors
	DietPlan();

	DietPlan(int goal, string name, string date);
	//copy constructor
	DietPlan& operator= (DietPlan& rhs);

	//getters
	int getGoal();
	string getName();
	string getDate();

	//setters
	void setGoal(int newGoal);
	void setGoal(string newGoal);

	void setName(string newName);

	void setDate(string newDate);



private:
	int goal;
	string name;
	string date;



};

std::ifstream& operator>> (std::ifstream& lhs, DietPlan& rhs);
std::ofstream& operator<< (std::ofstream& lhs, DietPlan& rhs);

ostream& operator<< (ostream& lhs, DietPlan& rhs);
