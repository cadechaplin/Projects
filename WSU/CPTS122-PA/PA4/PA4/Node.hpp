#pragma once
#include "ExercisePlan.hpp"
#include "DietPlan.hpp"

class Node
{

public:
	DietPlan diet;
	ExercisePlan ex;
	Node* next;

};




