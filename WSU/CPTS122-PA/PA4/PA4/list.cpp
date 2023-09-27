#include "List.hpp"




List::List() {

	head = (class Node*)malloc(sizeof(Node));
	head = nullptr;




}




void addNode(List* mainList, DietPlan &diet, ExercisePlan &ex) {
	Node* pMem = (class Node*)malloc(sizeof(Node));
	
	pMem->diet = *(&diet);
	pMem->ex = ex;

	if (mainList->head == NULL) {
		mainList->head = pMem;
		pMem->next = NULL;
	}
	else
	{
		pMem->next = mainList->head;
		mainList->head = pMem;

	}


}