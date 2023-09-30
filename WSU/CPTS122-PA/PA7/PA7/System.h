#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "Record.h"
#include "ArrayStack.h"

class System {
public:
	void run();
	



	/*
	1.    Import course list

2.    Load master list

3.    Store master list

4.    Mark absences

5.    BONUS: Edit absences

6.    Generate report

7.    Exit
	*/


private:
	List<Record> studentList;
	void report1();
	void report2();

	void importCourseList();

	void importMasterList();

	void StoreMasterList();

	void editAbsences();//

	void markAbsences();

	void reportMenu();

	void editAbsence();// weird problem where report says student with no absence still has a removed absence but the masterlist export still shows corect info
};

string getDate();