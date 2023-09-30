#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"
#include <fstream>
#include "string.h"

class DataAnalysis{
public:
	void run();

private:
	BST mTreePurchased;
	BST mTreeSold;
	std::ifstream input;

	void openfile();
	void insertfile();
	bool insertLine();
	void presentData();
};