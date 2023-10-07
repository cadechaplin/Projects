#include "AVLNode.h"

template <typename T>
class AVLTree{
    public:
    AVLTree();
    ~AVLTree();
    int height();
    bool validate();
    void insert(T val);
    bool contains(T val);
    private:
    AVLNode<T>* root;

};


template <typename T>
AVLTree<T>::AVLTree(){
this->root = nullptr;


}

template <typename T>
AVLTree<T>::~AVLTree(){


    
}

template <typename T>
void AVLTree<T>::insert(T val){
    if(this->root == nullptr){
        this->root = new AVLNode<T>(val);
        return;
    }
    this->root->insert(val);
    return;
    
}
template <typename T>
bool AVLTree<T>::validate(){
    if(root == nullptr){
        return true;
    }else{

        return root->validate();
    }
}
template<typename T>
bool AVLTree<T>::contains(T val){

    if(root == nullptr){
        return false;
    }
    return root->search(val);
}
template<typename T>
int AVLTree<T>::height(){
    if(root == nullptr){
        return 0;
    }else{
        return root->height;
    }


}