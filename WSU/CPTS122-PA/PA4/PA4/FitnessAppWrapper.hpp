#pragma once

#include "DietPlan.hpp"

class FitnessAppWrapper
{
public: 
	
	void loadWeeklyPlan(DietPlan diet[7]);
	void loadWeeklyPlan(ExercisePlan ex[7]);

	void loadDailyPlan(DietPlan *diet, std::ifstream &inputStream);
	void loadDailyPlan(ExercisePlan *ex, std::ifstream& inputStream);

	//setters
	//void loadDailyPlan();
	void storeWeeklyPlan(DietPlan plan[7]);
	void storeWeeklyPlan(ExercisePlan plan[7]);

	

	void displayWeeklyPlan(DietPlan plan[7]);
	void displayWeeklyPlan(ExercisePlan plan[7]);

	void displayDailyPlan(DietPlan play[1]);
	void displayDailyPlan(ExercisePlan play[1]);


	 void storeDailyPlan (DietPlan diet, std::ofstream &inputStream);
	 void storeDailyPlan(ExercisePlan diet, std::ofstream& inputStream);


	 void editWeeklyPlan(DietPlan diet[7]);
	 void editWeeklyPlan(ExercisePlan diet[7]);


	 void editDailyPlan(DietPlan diet[1]);
	 void editDailyPlan(ExercisePlan diet[1]);


	 
	 int displayMenu();
	//storeWeeklyPlan ();

	//displayMenu ();


private:

	
};

