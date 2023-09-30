#include "Record.h"
Record::Record() {

	recordNum = 0;
	int IDnum = 0;
	firstName = "blank";
	lastName = "blank";
	email = "blank";
	units = "blank";
	major = "blank";
	level = "blank";
	totalAb = 0;







}

Record::~Record() {



}






void Record::setRecordNum(int num) {

	recordNum = num;




}


void Record::setIDnum(int num) {
	IDnum = num;
}
void Record::setFirstName(string word) {
	firstName = word;
}
void Record::setLastName(string word) {

	lastName = word;

}
void Record::setEmail(string word) {
	email = word;

}
void Record::setUnits(string num) {
	units = num;

}
void Record::setMajor(string word) {
	major = word;

}
void Record::setLevel(string word) {
	level = word;
}
//stack
void Record::setTotalAb(int num) {
	totalAb = num;

}

string Record::getFirstName() {
	return firstName;
}

string Record::getLastName() {
	return lastName;
}

string Record::getUnits() {
	return units;
}
string Record::getEmail() {
	return email;
}

string Record::getMajor() {
	return major;
}

string Record::getLevel() {
	return level;
}

int Record::getRecordNum() {

	return recordNum;



}

int Record::getIDnum() {

	return IDnum;



}
int Record::getTotalAb() {

	return totalAb;



}


void Record::addAb(string date) {


	daysAb.insert(date);
	totalAb++;
}

string Record::popAb() {

	if (totalAb > 0) {
		string temp = daysAb.peek();
		totalAb--;
		return temp;

	}
	return "no absence";
}

string Record::peek() {
	
	if (daysAb.getMaxSize() > 0) {
		return ("Last absence: " + daysAb.peek());
	}
	else
	{
		return "No absences";
	}


}

void Record::removeAb(string rSearch){
	

	daysAb.remove(rSearch);
	totalAb = daysAb.getMaxSize();
	
	}


ostream& operator<<(ostream& os, Record rhs) {

	os << rhs.getRecordNum() << "," << rhs.getIDnum() << "," << rhs.getFirstName() << "," << rhs.getLastName() << "," << rhs.getEmail() << "," << rhs.getUnits() << "," << rhs.getMajor() << "," << rhs.getLevel() << "," <<
		rhs.getTotalAb();
	while(rhs.getTotalAb() > 0)
	{
		os << "," << rhs.popAb();
	}



	return os;
}



//string daysAb[];