#include "Node.h"


Node::Node() {

	data = "blank";
	mpLeft = nullptr;
	mpRight = nullptr;
	



}


Node::Node(std::string newdata) {

	data = newdata;
	mpLeft = nullptr;
	mpRight = nullptr;




}
Node::~Node() {






}



void Node::setRight(Node* newNode) {

	mpRight = newNode;



}


void Node::setLeft(Node* newNode) {

	mpLeft = newNode;



}

Node* Node::getRight() {



	return mpRight;

}

Node* Node::getLeft() {

	if (this == nullptr)
	{
		return nullptr;
	}

	return mpLeft;

}

transactionNode::transactionNode(std::string data1, int data2) {
	data = data1;
	mUnits = data2;




}

transactionNode::~transactionNode(){



}

void transactionNode::setUnits(int newUnits) {

	mUnits = newUnits;


}

int transactionNode::getUnits() {


	return mUnits;

}
void transactionNode::printData() {

	std::cout << data << ": " << mUnits << std::endl;


}
int transactionNode::getData() {

	return mUnits;

}


std::ostream& operator<<(std::ostream& os, transactionNode* rhs) {

	os << rhs->getData() << rhs->getUnits();
	


	return os;
}
