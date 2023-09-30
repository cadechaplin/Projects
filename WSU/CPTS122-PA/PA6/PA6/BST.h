#pragma once

#include "BSTNode.h"



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
class BST
{
public:
	BST();
	BST(int file);
	~BST();

	void insert(const T newData, const F newData2);

	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();
	void search(T letter);


private:
	Node<T, F>* mpRoot;

	void insert(Node<T, F>* const pNewRoot, const T newData, const F newData2);

	void inorderTraversal(Node<T, F>* const pTree);
	void preorderTraversal(Node<T, F>* const pTree);
	void postorderTraversal(Node<T, F>* const pTree);

	void destroyTree(Node<T, F>* const pTree);

	void search(T letter, Node<T, F>* const pTree);

};

template <class T, class F>
BST<T, F>::BST()
{
	Node<T, F>* newpRoot = nullptr;
	this->mpRoot = newpRoot;
}


template <class T, class F>
BST<T, F>::BST(int file)
{

	std::ifstream input;

	input.open("MorseTable.txt", std::ios::in);

	
	

	T letter;
	string line;

	F morse;
	while (input.is_open())
	{



		getline(input, line);





		if (line[0] == '\0') {
			input.close();
		}
		else
		{
			letter = line[0];

			morse = line.substr(2, line.size());


			
			this->insert(letter, morse);

		}
		


	}





	
}


template <class T, class F>
BST<T, F>::~BST()
{
	destroyTree(this->mpRoot);
}

// public
template <class T, class F>
void BST<T, F>::insert(const T newData, const F newData2)
{
	insert(this->mpRoot, newData, newData2);
}

// private - recursive
template <class T, class F>
void BST<T, F>::insert(Node<T, F>* const pNewRoot, const T newData, const F newData2)
{
	if (pNewRoot == nullptr)
	{
		// empty tree
		this->mpRoot = new Node<T, F>(newData, newData2);
	}
	else if (pNewRoot->getData() < newData)
	{
		if (pNewRoot->getRightPtr() != nullptr)
		{
			// there's more right subtree to traverse
			insert(pNewRoot->getRightPtr(), newData, newData2);
		}
		else
		{
			// the current right subtree is empty
			// we found the place to insert
			pNewRoot->setRightPtr(new Node<T, F>(newData, newData2));
		}
	}
	else if (newData < pNewRoot->getData())
	{
		// trying to traverse left subtree
		if (pNewRoot->getLeftPtr() != nullptr)
		{
			insert(pNewRoot->getLeftPtr(), newData, newData2);
		}
		else
		{
			// the left ptr of the current Node is null so don't traverse, we found
			// where to insert.
			pNewRoot->setLeftPtr(new Node<T, F>(newData, newData2));
		}
	}
	else // duplicate
	{
		cout << "duplicate: " << newData << endl;
	}
}

template <class T, class F>
void BST<T, F>::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

template <class T, class F>
void BST<T, F>::inorderTraversal(Node<T, F>* const pTree)
{
	// visit the nodes in left, process, right traversing

	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeftPtr());
		cout << "pTree's Data: " << pTree->getData() << endl;
		inorderTraversal(pTree->getRightPtr());
	}
}

template <class T, class F>
void BST<T, F>::preorderTraversal()
{
	preorderTraversal(this->mpRoot);
}

template <class T, class F>
void BST<T, F>::preorderTraversal(Node<T, F>* const pTree)
{
	// visit the nodes in process, left, right traversing

	if (pTree != nullptr)
	{
		cout << "pTree's Data: " << pTree->getData() << endl;
		preorderTraversal(pTree->getLeftPtr());
		preorderTraversal(pTree->getRightPtr());
	}
}
template <class T, class F>
void BST<T, F>::postorderTraversal()
{
	postorderTraversal(this->mpRoot);
}

template <class T, class F>
void BST<T, F>::postorderTraversal(Node<T, F>* const pTree)
{
	// visit the nodes in left, right, process traversing

	if (pTree != nullptr)
	{
		postorderTraversal(pTree->getLeftPtr());
		postorderTraversal(pTree->getRightPtr());
		cout << "pTree's Data: " << pTree->getData() << endl;

	}
}

template <class T, class F>
void BST<T, F>::destroyTree(Node<T, F>* const pTree)
{
	// we are performing a postorder traversal
	// to delete all the remaining nodes in the tree.
	// the root is the last node deleted!

	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree; // invokes destructor for a node
	}
}

template <class T, class F>
void BST<T, F>::search(T letter)
{
	// visit the nodes in left, process, right traversing
	search(letter, this->mpRoot);
	
}

template <class T, class F>
void BST<T, F>::search(T letter, Node<T, F>* const pTree)
{
	

	if (pTree != nullptr)
	{
		
		if (pTree->getData() == letter) {// if data matches print to screen, otherwise keep looking

			cout << pTree->getData2();// Needs to be data2
			

		}
		else
		{
			search(letter, pTree->getLeftPtr());
			//cout << "pTree's Data: " << pTree->getData() << endl;
			search(letter, pTree->getRightPtr());
		}
		
		
	}
	
	
}


/*
template <class T, class F>
T add(T n1, T n2);

template <class T, class F>
T add(T n1, T n2)
{
	return n1 + n2;
}
*/



/*

class BST {

public:

	BST();

	~BST();

	void InsertNode(std::string newString);

	void inorderTraversal();

	void preOrderTraversal();

	void postOrderTraversal();
	bool isEmpty();

	BSTNode* gethead();

private:

	BSTNode* pRoot;

	void destroyTree(BSTNode* pMem);

	void InsertNode(BSTNode* pRoot, std::string newString);

	void inorderTraversal(BSTNode* pMem);

	void preOrderTraversal(BSTNode* pMem);

	void postOrderTraversal(BSTNode* pMem);

	bool isEmpty(BSTNode* pTree);



};

*/