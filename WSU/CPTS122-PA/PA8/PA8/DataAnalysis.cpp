#include "DataAnalysis.h"




void DataAnalysis::run() {

	openfile();
	insertfile();
	presentData();
}


void DataAnalysis::openfile() {

	input.open("data.csv");



}

void DataAnalysis::insertfile(){

	while (insertLine());


}
bool DataAnalysis::insertLine() {
	std::string line;
	std::getline(input, line);
	if (line.size() != 0)
	{


		std::string purchased = "blank";

		std::string name;

		std::string units;
		char* dup = _strdup(line.c_str());
		units = strtok(dup, ",");
		name = strtok(NULL, ",");
		purchased = strtok(NULL, "\n");

		if (purchased != "blank") {
			if (purchased == "Sold") {

				mTreeSold.insert(name, stoi(units));


			}
			else if (purchased == "Purchased") {

				mTreePurchased.insert(name, stoi(units));


			}
		}
		
	}
	return !input.eof();
}

void DataAnalysis::presentData() {
	Node* largest = mTreeSold.findLargest();
	Node* smallest = mTreeSold.findSmallest();
	std::cout << "Sold Trees Data:" << std::endl;
	mTreeSold.inOrderTraversal();
std::cout<< std::endl << "Sold the most: " << std::endl;
largest->printData();
std::cout << std::endl << "Sold the least: " << std::endl;
smallest->printData();

std::cout << std::endl;

	
std::cout << "Purchased Trees Data:" << std::endl;
mTreePurchased.inOrderTraversal();
std::cout << std::endl;

largest = mTreePurchased.findLargest();
smallest = mTreePurchased.findSmallest();
std::cout << std::endl << "Purchased the most: " << std::endl;
largest->printData();

std::cout << std::endl << "Purchased the least: " << std::endl;
smallest->printData();


}