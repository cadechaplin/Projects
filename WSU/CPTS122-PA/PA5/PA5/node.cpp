#include "node.h"


Node::Node(int id, int time, int line) {
	Data* pMem = new Data(id, time, line);


	this->pData = pMem;
	this->pNext = nullptr;



}

Node::~Node() {



}


void Node::setNextPtr(Node* newNextPtr) {

	this->pNext = newNextPtr;

}

void Node::min() {

	this->pData->min();

}

int Node::custTime() {


	return this->pData->getTime();

}

Node* Node::getNext()
{
	return this->pNext;
}


int Node::getID() {

	return this->pData->getID();


}

Data Node::getData() {

	return *(this->pData);


}