#pragma once
#include "Node.h"
class BST {
public:
	BST();
	~BST();

	void destroyTree(Node* pCur);

	void setRoot(Node* pRoot);
	Node* getPRoot();
	void insert(std::string item, int units);
	void inOrderTraversal();

	Node* findLargest();
	Node* findSmallest();


private:
	Node* mpRoot;
	
	void insert(Node* pNewRoot, std::string item, int units);
	void inOrderTraversal(Node* pCur);
};