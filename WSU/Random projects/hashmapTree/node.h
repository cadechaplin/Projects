#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


template <class T>
class Node {
public:

    Node();
    ~Node();
    virtual void insert(T data, int val);
    virtual bool isList();
    virtual bool isMap();
    virtual int slotVal();
    virtual bool find(T data, int val);
    
};

template <class T>
Node<T>::Node(){

  
};


template <class T>
Node<T>::~Node(){};

template <class T>
void Node<T>::insert(T data, int val){};

template <class T>
bool Node<T>::isList(){
return false;

}

template <class T>
bool Node<T>::isMap(){
return false;

}

template<class T>
int Node<T>::slotVal(){
    return -1;



}

template <class T>
bool Node<T>::find(T data, int val){
return false;

}