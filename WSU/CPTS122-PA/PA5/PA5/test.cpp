#include "test.h"





bool test::test1() {



	sample = ex.enqueue(10, 10, 10);// adds node to queue and returns the data in the node 
	
	if (sample.getID() == 10) {//if the data in the node is what was attempted to add, return true 
		return true;
	}
	else
	{
		return false;
	}




}

bool test::test2() {// adds node to queue and returns the data in the node, one node already in queue from test 1

	Node* pMem = ex.getHead();

	sample = ex.enqueue(30, 10, 10);//if what was added was what was attempted then 
	
	

	

	if (sample.getID() == 30 && pMem == ex.getHead()) {//data added was what was attempted and head has not changed 
		return true;
	}
	else
	{
		return false;
	}




}

bool test::test3() {


	
	sample = ex.dequeue();//returns data from node that was dequeued 
	if (sample.getID() == 10) {//checks to see if what was dequeued was the correct node 
		return true;
	}
	else
	{
		return false;
	}


}

bool test::test4() {

	
	sample = ex.dequeue();
	if ((sample.getID() == 30) && ex.getHead() == nullptr) {//makes sure correct node was removed and that queue is empty 
		return true;
	}
	else
	{
		return false;
	}




}

bool test::test5(int num) {//runs program if user wants to, makes a massive mess on the screen so I put the option to not run this test if you want



	if (num == 1) {


		program(1440);
		return true;

	}
	else {
		return false;//if you don't run the test it will fail
	}


}
void test::testWrapper() {//runs all tests

	cout << "1 = success, 0 = failed\n";

	cout << "Test 1:	" << test1() << "\n";
	cout << "Test 2:	" << test2() << "\n";
	cout << "Test 3:	" << test3() << "\n";
	cout << "Test 4:	" << test4() << "\n";
	int num = 0;
	cout << "Run test 5? enter 1\n";
	cin >> num;
	cout << "Test 5:	" << test5(num) << "\n";


}