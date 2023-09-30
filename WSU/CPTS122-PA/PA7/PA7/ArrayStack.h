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
class AStack
{
public:
	AStack();
	~AStack();

	void insert(T newData);
	T pop();
	T peek();
	int getMaxSize();
	void remove(T sItem);

private:
	
	
	
	T stack[10];
	int maxSize;
	T blank;


};

template <class T>
AStack<T>::AStack() {

	
	maxSize = 0;
	


}

template <class T>
AStack<T>::~AStack() {

	



}

template<class T >
int AStack<T>::getMaxSize() {

	return maxSize;



}

template <class T>
void AStack<T>::insert(T newData) {

	if (maxSize >= 10) {
	
		cout << "max absences reached" << endl;
	
	
	}
	else
	{
		stack[maxSize] = newData;
		//cout << newData << " added " << endl;
		maxSize++;
	}






}

template <class T>
T AStack<T>::peek() {
	return stack[maxSize-1];


}

template <class T>
T AStack<T>::pop() {
	if (maxSize != 0) {
		
		maxSize--;
		return stack[maxSize];
	}
	else {
	
		cout << "stack is empty" << endl;
		return blank;
	}

}
template <class T>
void AStack<T>::remove(T sItem) {


	T temp;
	AStack<T> tStack;

	while (this->maxSize > 0) {
		temp = this->pop();


		if (temp != sItem) {
			tStack.insert(temp);
		
		}


	}

	*this = tStack;

}