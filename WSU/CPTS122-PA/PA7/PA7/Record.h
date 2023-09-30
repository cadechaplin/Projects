#pragma once

#include "ArrayStack.h"
#include <iostream>


using std::string;
using std::ostream;
class Record
{
public:
	Record();
	~Record();



	


	void setRecordNum(int num);
	void setIDnum(int num);
	void setFirstName(string word);
	void setLastName(string word);
	void setEmail(string word);
	void setUnits(string num);
	void setMajor(string word);
	void setLevel(string word);
	//stack
	void setTotalAb(int num);
	//string daysAb[];
	string getLastName();
	string getFirstName();
	string getEmail();
	string getUnits();
	string getMajor();
	string getLevel();
	int getTotalAb();
	int getRecordNum();
	int getIDnum();
	void addAb(string date);
	string popAb();
	string peek();
	void removeAb(string rSearch);
	/*
	Node(const T newData, const F newData2);

	~Node();

	T getData() const;
	F getData2() const;

	Node<T, F>* getLeftPtr() const;
	Node<T, F>* getRightPtr() const;

	void setLeftPtr(Node<T, F>* const pNewLeftPtr);
	void setRightPtr(Node<T, F>* const pNewRightPtr);
	*/

private:
	int recordNum;
	int IDnum;
	string firstName;
	string lastName;
	string email;
	string units;
	string major;
	string level;
	//stack
	int totalAb;
	//string daysAb[];
	AStack <string> daysAb;


};


std::ostream& operator<<(std::ostream& os, Record rhs);

