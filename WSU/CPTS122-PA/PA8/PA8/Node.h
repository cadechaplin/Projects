#pragma once
//#include "Node.cpp"
#include <string>
#include <iostream>

class Node {
public:
	Node();
	Node(std::string data);
	virtual ~Node();


	void setRight(Node* newNode);
	void setLeft(Node* newNode);
	Node* getRight();
	Node* getLeft();

	virtual void printData() = 0;
	virtual int getData() = 0;
private:

	


protected:
	std::string data;

	Node* mpRight;

	Node* mpLeft;

};



class transactionNode: public Node{
public:
	transactionNode(std::string data1, int data2);
	~transactionNode();


	void setUnits(int newUnits);
	int getUnits();
	int getData();
	void printData();
private:



	int mUnits;


};



std::ostream& operator<<(std::ostream& os, transactionNode* rhs);