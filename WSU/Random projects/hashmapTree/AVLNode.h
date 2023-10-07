

#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class AVLNode{
    public:
	AVLNode(T val);
	~AVLNode();
    
    
	T getData();
	void insert(T val);
	bool validate();
	bool search(T val);
	int height;
    private:
	
	int getBF();
	int maxChildHeight();
	void rotateLeft();
	void rotateRight();
	AVLNode<T>* getMax(AVLNode<T>* pCur);
	AVLNode<T>* getMin(AVLNode<T>* pCur);
	T data;
	
    AVLNode* right;
    AVLNode* left;
	
};

template<typename T>
    AVLNode<T>::AVLNode(T val) {
		this->data = val;
		this->left = nullptr;
		this->height = 0;
		this->right = nullptr;
	}

template<typename T>
AVLNode<T>::~AVLNode()//deletes nodes in post order to make sure all nodes underneath current node are deleted before deleting current node
	{
		if(left != nullptr){
			delete left;

		}
		if(right!= nullptr){
			delete right;

		}
		//cout << "deleting node with: " << this->value << endl;
	}

template<typename T>
T AVLNode<T>::getData(){

	return this->data;

}

template<typename T>
void AVLNode<T>::insert(T val){
	if(this->data == val){
		return; // value already contained

	}

	if(val > this->data){
		
		if(this->right == nullptr){
			this->right = new AVLNode(val);
			
			
		}else{
		this->right->insert(val);
		}
		
		height = maxChildHeight() +1;
		
        
        
    }else{
		
		if(this->left == nullptr){
			this->left = new AVLNode(val);
			
		}else{
		this->left->insert(val);
		}
		height = maxChildHeight() +1;

        
        
    }
	int bf = getBF();
	
	
		if(bf < -1){
			if(this->left->getBF() > 0){
			this->left->rotateLeft();
			}
			this->rotateRight();


		}
		if(bf > 1 ){
			if(this->right->getBF() < 0){
				this->right->rotateRight();
			}

			this->rotateLeft();

		}
		if(getBF() > 1 || getBF() < -1){
			cout << "bug";

		};

	

	
	

	
}



template<typename T>
void AVLNode<T>::rotateLeft() {
	
	
	
	
	AVLNode<T>* oldRoot = new AVLNode(this->data);// cut this part of the tree off from parent so that the current root can be updated later
	oldRoot->right = this->right;
	oldRoot->left = this->left;




	AVLNode<T>* newRoot = oldRoot->right;
	oldRoot->right = newRoot->left;
	newRoot->left = oldRoot;
	oldRoot->height = 1 + oldRoot->maxChildHeight();




	this->data = newRoot->data; //update the node the parent points to so that the tree holds
	this->right = newRoot->right;
	this->left = newRoot->left;
	this->height = 1 + newRoot->maxChildHeight();
	newRoot->left = nullptr;//disconnect node so that deconstructor does destroy the tree
	newRoot->right = nullptr;
	delete newRoot; // delete temp node

   
    
    
}
    
template<typename T>
void AVLNode<T>::rotateRight() {
	
	
	
    AVLNode<T>* oldRoot = new AVLNode(this->data);// cut this part of the tree off from parent so that the current root can be updated later
	oldRoot->right = this->right;
	oldRoot->left = this->left;




	AVLNode<T>* newRoot = oldRoot->left;
	oldRoot->left = newRoot->right;
	newRoot->right = oldRoot;

	oldRoot->height = 1 + oldRoot->maxChildHeight();
	


	this->data = newRoot->data; //update the node the parent points to so that the tree holds
	this->right = newRoot->right;
	this->left = newRoot->left;
	this->height = 1 + newRoot->maxChildHeight();
	newRoot->left = nullptr;//disconnect node so that deconstructor does destroy the tree
	newRoot->right = nullptr;
	delete newRoot; // delete temp node

}

template<typename T>
int AVLNode<T>::maxChildHeight(){
if(right == nullptr && left == nullptr){
	return -1;
}
if(right == nullptr){
	return left->height;
}
if(left == nullptr){
return right->height;
}
if(left->height > right->height){
	return left->height;
	
}
return right->height;

}
template<typename T>
AVLNode<T>* AVLNode<T>::getMax(AVLNode<T>* pCur){
while(pCur->right != nullptr){
	pCur = pCur->right;
}
	return pCur;
}
template<typename T>
AVLNode<T>* AVLNode<T>::getMin(AVLNode<T>* pCur){
while(pCur->left != nullptr){
	pCur = pCur->left;
}
	return pCur;
}
template<typename T>
bool AVLNode<T>::validate(){
if(this->left != nullptr){
	if(this->right == nullptr){
		if(this->left->height > 0){
			return false;
		}

	}
	else if(this->right != nullptr){
		if(this->left->height - this->right->height > 1 || this->left->height - this->right->height < -1 ){
			return false;
		}


	}
	if(this->height <= this->left->height){
		return false;

	}
	if(! left->validate()){
		return false;

	}


}
if(this->right != nullptr){
	if(this->left == nullptr){
		if(this->right->height > 0){
			return false;
		}

	}
	else if(this->left != nullptr){
		if(this->right->height - this->left->height > 1 || this->right->height - this->left->height < -1 ){
			return false;
		}


	}
	if(this->height <= this->right->height){
		return false;

	}
	if(! right->validate()){
		return false;

	}

	
}
	return true;

}
template<typename T>
bool AVLNode<T>::search(T val){
	if(this->data == val){
		return true;
	}
	if(this->data < val){
		if(this->right == nullptr){return false;}
		return this->right->search(val);
	}
	if(this->data > val ){
		if(this->left == nullptr){return false;}
		return this->left->search(val);
	}
	return false;
}

template <typename T>
int AVLNode<T>::getBF(){
	if(right == nullptr && left == nullptr){
		return 0;
	}
	int bf =0;

	if(right == nullptr){
		bf = -(left->height) - 1;

	}
	else if(left == nullptr){
		bf = (right->height) + 1;

	}else
	{
		bf =  right->height - left->height ;
	}
return bf;

} 