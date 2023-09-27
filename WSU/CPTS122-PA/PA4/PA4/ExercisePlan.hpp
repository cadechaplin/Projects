#pragma once

#include<iostream> 
#include <fstream>
#include <string>


using std::cout;
using std::ostream;
using std::string;

class ExercisePlan
{


public:
	//constructors
	ExercisePlan();
	ExercisePlan(int goal, string name, string date);

	//copy constructor
	ExercisePlan& operator= (ExercisePlan& rhs);

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


std::ifstream& operator>> (std::ifstream& lhs, ExercisePlan& rhs);
std::ofstream& operator<< (std::ofstream& lhs, ExercisePlan& rhs);

ostream& operator<< (ostream& lhs, ExercisePlan& rhs);