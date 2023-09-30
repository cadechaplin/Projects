#include "queue.h"


Queue::Queue(Node* newpHead, Node* newpTail)
{
	this->pHead = newpHead; 
	this->pTail = newpTail;


}

Queue:: ~Queue() {

	void destroyQueue();


}

Data Queue::enqueue(int id, int time, int line) {

	Node* pMem = new Node(id, time, line);
	
	Data tempData = pMem->getData();

	if (pMem != nullptr)
	{
		

		if (isEmpty())
		{
			this->pHead = this->pTail = pMem;
		}
		else
		{
			
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
		}

	}

	return tempData;




} 


bool Queue::isEmpty()
{
	return this->pHead == nullptr;
}

void Queue::min() {

	if (isEmpty() == false)
	{

		pHead->min();

	}





}

int Queue::custTime() {

	if (isEmpty()) {
		return 1;
	
	}
	else
	{
		return pHead->custTime();
	}
}



Data Queue::dequeue()
{
	Node* pTemp = this->pHead;
	Data info = pTemp->getData();
	


	if (this->pHead == this->pTail)
	{
		// one node in queue
		this->pHead = this->pTail = nullptr;
	}
	else // there is more than one node in the queue
	{
		// we just need to update the head ptr
		this->pHead = pTemp->getNext();
	}

	// remove the front node
	delete pTemp; // will implicitly invoke the destructor for a node
	
	
	return info;
}

void Queue::leftOver() {


	if (isEmpty() == false) {
	
	
		cout << this->pHead->getID() << "\n";
		dequeue();
	
	
		leftOver();
	
	}

}

Node* Queue::getHead() {

	return this->pHead;



}


void Queue::destroyQueue() {


	while(pTail != nullptr){
		Node* pTemp = pHead;
		pHead = pHead->getNext();

		cout << "destorying " << pTemp->getID() << "\n";
		delete pTemp;
	
	
	}


}

void Queue::print() {

	if (this->getHead() != nullptr)
	{
		
		printQ(this->pHead);
		
	}


	cout << "\n";
}

void Queue::printQ(Node * pCur) {

	if (pCur != nullptr) {
	
		cout << pCur->getID() << " ";
	
		printQ(pCur->getNext());
	}



}
