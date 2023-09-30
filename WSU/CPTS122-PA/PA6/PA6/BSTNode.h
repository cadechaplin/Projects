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

template <class T, class F>
class Node
{
public:
	Node(const T newData, const F newData2);

	~Node();

	T getData() const;
	F getData2() const;

	Node<T, F>* getLeftPtr() const;
	Node<T, F>* getRightPtr() const;

	void setLeftPtr(Node<T, F>* const pNewLeftPtr);
	void setRightPtr(Node<T, F>* const pNewRightPtr);

private:
	T mData;
	F fData;
	Node<T, F>* mpLeft;
	Node<T, F>* mpRight;
};

template <class T, class F>
Node<T, F>::Node(const T newData, const F newData2)
{
	this->mData = newData;
	this->fData = newData2;

	this->mpLeft = this->mpRight = nullptr;
}

template <class T, class F>
Node<T, F>::~Node()
{
	//cout << "deleting the Node that contains: " << this->mData << " and " << this->fData << endl;
}

template <class T, class F>
T Node<T, F>::getData() const
{
	return this->mData;
}

template <class T, class F>
F Node<T, F>::getData2() const
{
	return this->fData;
}

template <class T, class F>
Node<T, F>* Node<T, F>::getLeftPtr() const
{
	return this->mpLeft;
}

template <class T, class F>
Node<T, F>* Node<T, F>::getRightPtr() const
{
	return this->mpRight;

}

template <class T, class F>
void Node<T, F>::setLeftPtr(Node<T, F>* const pNewLeftPtr)
{
	this->mpLeft = pNewLeftPtr;
}

template <class T, class F>
void Node<T, F>::setRightPtr(Node<T, F>* const pNewRightPtr)
{
	this->mpRight = pNewRightPtr;

}
/*

class BSTNode {

public:

	//constructors
	BSTNode();

	BSTNode(std::string newData);


	//getters 
	BSTNode* getRight();

	BSTNode* getLeft();

	std::string getData();

	//setters
	void setRight(BSTNode* newNode);

	void setLeft(BSTNode* newNode);

	void setData(std::string newString);

	//

private:

	BSTNode* pRight;

	BSTNode* pLeft;

	std::string morse;


};

*/