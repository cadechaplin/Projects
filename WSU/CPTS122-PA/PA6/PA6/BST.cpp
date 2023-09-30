#include "BST.h"


/*

BST::BST() {

	pRoot = nullptr;


}

BST::~BST() {

	destroyTree(this->pRoot);


}



void BST::InsertNode(std::string newString) {


	InsertNode(this->pRoot, newString);







}

void BST::InsertNode(BSTNode* pNewRoot, std::string newString) {

	if (pNewRoot == nullptr)
	{
		// empty tree
		this->pRoot = new BSTNode(newString);
	}
	else if (newString > pNewRoot->getData())
	{
		if (pNewRoot->getRight() != nullptr)
		{
			// there's more right subtree to traverse
			InsertNode(pNewRoot->getRight(), newString);
		}
		else
		{
			// the current right subtree is empty
			// we found the place to insert
			pNewRoot->setRight(new BSTNode(newString));
		}
	}
	else if (newString < pNewRoot->getData())
	{
		// trying to traverse left subtree
		if (pNewRoot->getLeft() != nullptr)
		{
			InsertNode(pNewRoot->getLeft(), newString);
		}
		else
		{
			// the left ptr of the current Node is null so don't traverse, we found
			// where to insert.
			pNewRoot->setLeft(new BSTNode(newString));
		}
	}
	else // duplicate
	{
		std::cout << "duplicate: " << newString << std::endl;
	}



}

void BST::inorderTraversal()
{
	inorderTraversal(this->pRoot);
}

void BST::inorderTraversal(BSTNode* const pTree)
{
	// visit the nodes in left, process, right traversing

	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeft());
		std::cout << "pTree's Data: " << pTree->getData() << std::endl;
		inorderTraversal(pTree->getRight());
	}
}

void BST::preOrderTraversal() {

	preOrderTraversal(this->pRoot);


}

void BST::preOrderTraversal(BSTNode* pTree) {



	if (pTree != nullptr)
	{

		std::cout << "pTree's Data: " << pTree->getData() << std::endl;
		preOrderTraversal(pTree->getLeft());
		preOrderTraversal(pTree->getRight());
	}


}


void BST::postOrderTraversal() {
	postOrderTraversal(this->pRoot);



}

void BST::postOrderTraversal(BSTNode* pTree) {


	if (pTree != nullptr)
	{
		preOrderTraversal(pTree->getLeft());
		preOrderTraversal(pTree->getRight());
		std::cout << "pTree's Data: " << pTree->getData() << std::endl;
	}
}


void BST::destroyTree(BSTNode* pMem) {


	if (pMem != nullptr)
	{
		destroyTree(pMem->getLeft());
		destroyTree(pMem->getRight());
		std::cout << "destroying: " << pMem->getData() << std::endl;
		delete pMem; // invokes destructor for a node
	}



}
bool BST::isEmpty() {
	return isEmpty(this->pRoot);


}

bool BST::isEmpty(BSTNode* pTree) {

	if (pTree == nullptr)
	{
		return true;
	}
	else {
		return false;
	}


}


BSTNode* BST::gethead() {

	return pRoot;





}

*/