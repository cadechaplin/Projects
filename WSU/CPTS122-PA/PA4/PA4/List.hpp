#pragma once

#include "Node.hpp"

class List
{
public:
	//constructor
	List();



	Node* head;

};

void addNode(List* mainList, DietPlan &diet, ExercisePlan &ex);