#include "BST.h"
BST::BST() {

	mpRoot = NULL;


}


BST::~BST() {

	destroyTree(this->mpRoot);

}

void BST::destroyTree(Node* pCur) {

	if (pCur->getLeft() != NULL) {
	
		destroyTree(pCur->getLeft());
	
	}

	if (pCur->getRight() != NULL) {

		destroyTree(pCur->getRight());

	}



	delete pCur;
}
Node* BST::getPRoot() {
	return mpRoot;

}
void BST::setRoot(Node* pRoot) {



	mpRoot = pRoot;

}

void BST::insert(std::string item, int units) {

	insert(this->mpRoot,item, units);


}

void BST::insert(Node* pNewRoot,std::string newData, int newData2) {

	if (pNewRoot == nullptr) {
	
		mpRoot = new transactionNode(newData, newData2);
	
	}
	else if (pNewRoot->getData() < newData2)
	{
		if (pNewRoot->getRight() != nullptr)
		{
			// there's more right subtree to traverse
			insert(pNewRoot->getRight(), newData, newData2);
		}
		else
		{
			// the current right subtree is empty
			// we found the place to insert
			pNewRoot->setRight(new transactionNode(newData, newData2));
		}
	}
	else if (newData2 < pNewRoot->getData())
	{
		// trying to traverse left subtree
		if (pNewRoot->getLeft() != nullptr)
		{
			insert(pNewRoot->getLeft(), newData, newData2);
		}
		else
		{
			// the left ptr of the current Node is null so don't traverse, we found
			// where to insert.
			pNewRoot->setLeft(new transactionNode(newData, newData2));
		}
	}
	




}


void BST::inOrderTraversal() {


	inOrderTraversal(this->mpRoot);

}


void BST::inOrderTraversal(Node* pCur) {


	if (pCur != nullptr)
	{
		inOrderTraversal(pCur->getLeft());
		pCur->printData();
		inOrderTraversal(pCur->getRight());
	}

	

}

Node* BST::findLargest() {
	Node* pCur = mpRoot;

	while (pCur->getRight() != nullptr) {
		pCur = pCur->getRight();
	
	}
		
	return pCur;


}

Node* BST::findSmallest() {
	Node* pCur = mpRoot;

	while (pCur->getLeft() != nullptr) {
		pCur = pCur->getLeft();

	}

	return pCur;


}