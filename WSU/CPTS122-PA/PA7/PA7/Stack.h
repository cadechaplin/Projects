#pragma once
#include "StackNode.h"
template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	void insert(T newData);
	void pop();
	T peek();


private:
	void insert(StackNode<T>* pCur, T newData);
	StackNode<T>* pTop;





};


template <class T>
Stack<T>::Stack() {

	//new StackNode<T>* pNew = nullptr;
	this->pTop = nullptr;

}

template <class T>
Stack<T>::~Stack() {

	//mem leaks



}

template <class T>
void Stack<T>::insert(T newData) {


	insert(this->pTop, newData);
	




}

template <class T>
void Stack<T>::insert(StackNode<T>* pCur, T newData) {

	//new Node<T, F>(newData, newData2
	
	if (pCur == nullptr) {

		this->pTop = new StackNode<T>(newData);

	}
	else
	{
		this->pTop = new StackNode<T>(newData, pCur);
	}




}

template <class T>
void Stack<T>::pop() {

	

	if (this->pTop == nullptr) {

		

	}
	else
	{
		StackNode<T>* pCur = this->pTop;
		this->pTop = this->pTop->getNext();
		delete pCur;
	}




}

template <class T>
T Stack<T>::peek() {

	if (pTop == nullptr) {
	
		return 0;//returns 0 if stack is empty
	
	}

	return pTop->getData();



}