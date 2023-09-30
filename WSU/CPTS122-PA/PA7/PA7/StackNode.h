#pragma once 
template <class T>
class StackNode
{
public:
	StackNode();
	StackNode(T newData);
	StackNode(T newData, StackNode<T>* pNext);
	~StackNode();

	StackNode<T>* getNext();
	T getData();



private:

	StackNode<T>* pNext;
	T date;




};

template <class T>
StackNode<T>::StackNode(){
	
	StackNode<T>* pNew = nullptr;
	this->pNext = pNew;

}
template <class T>
StackNode<T>::~StackNode() {

	

}


template <class T>
StackNode<T>::StackNode(T newData) {

	this->date = newData;

	StackNode<T>* pNew = nullptr;
	this->pNext = pNew;

}


template <class T>
StackNode<T>::StackNode(T newData, StackNode<T>* pNext) {

	this->date = newData;

	//new StackNode<T>* pNew = nullptr;
	this->pNext = pNext;

}
template <class T>
StackNode<T>* StackNode<T>::getNext() {
	return this->pNext;


}

template <class T>
T StackNode<T>::getData() {
	

	return this->date;


}
