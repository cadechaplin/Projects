#pragma once






#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <class T>
class Node
{
public:
	Node(const T newData);

	~Node();

	T getData() const;
	
	void setData(T newData);

	Node<T>* getNext() const;
	

	void setNext(Node<T>* const pNewLeftPtr);
	
	void readList();// temp

private:
	
	T mData;
	
	Node<T>* mpNext;
	
	void readList(Node<T>* list); // temp
};

template <class T>
Node<T>::Node(const T newData)
{
	this->mData = newData;
	

this->mpNext = nullptr;
}

template <class T>
Node<T>::~Node()
{
	//cout << "deleting the Node that contains: " << this->mData << " and " << this->fData << endl;
}

template <class T>
T Node<T>::getData() const
{
	return this->mData;
}



template <class T>
Node<T>* Node<T>::getNext() const
{
	return this->mpNext;
}





template <class T>
void Node<T>::setNext(Node<T>* const pNewPtr)
{
	this->mpNext = pNewPtr;
}


template <class T>
void Node<T>::readList()
{
	
	cout << this->mData;
	readList(this->getNext);
}

template <class T>
void Node<T>::readList(Node<T>* pCur)
{
	cout << pCur->mData;

	if (pCur->getNext != nullptr) {

		readList(pCur->getNext);

	}
}

template <class T>
void Node<T>::setData(T newData)
{
	mData = newData;
}