#pragma once
#include "Node.h"

template <class T>
class List
{
public:
	List();
	~List();

	void insert(T newData);// probably needs to be passed by refrence
	void deleteList(Node<T>* pCur);
	Node<T>* getHead();
private:

	Node<T>* pHead;





};


template <class T>
List<T>::List() {
	pHead = nullptr;




}

template <class T>
List<T>::~List() {
	
	//no leaks!

	deleteList(this->pHead);


}


template <class T>
void List<T>::insert(T newData) {
	
	if (pHead == nullptr) {
		pHead = new Node<T>(newData);
	
	
	}
	else {//fixed
		Node<T>* pCur = new Node<T>(newData);
		pCur->setNext(this->pHead);
		pHead = pCur;
	
	
	}


}

template <class T>
void List<T>::deleteList(Node<T>* pCur) {


	if (pCur != nullptr) {
		deleteList(pCur->getNext());
	//	cout << "deleted" << endl;
	}
	
	delete pCur;


}

template <class T>
Node<T>* List<T>::getHead() {

	return this->pHead;


}