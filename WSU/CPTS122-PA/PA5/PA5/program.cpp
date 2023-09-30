#include "Program.h"



void program(int num) {




	Queue Ex;
	Queue Reg;
	
	int choice = 0;
	
		int id = 0;//sets Id number 
		int newReg = 1 + (rand() % 6);//decides when new customer comes to regular line 
		int newEx = 1 + (rand() % 5);//decides when new customer comes to express line 
		
		int curWait = 0;//current wait in express line
		int curWait2 = 0; // current wait in regular line 
		
		num++;
		Data output;// data object that will be used for outputing what customer left or joined the line
		for (int i = 1; i < num; i++)// i is equal to minutes of time 
		{
			
			if (Ex.custTime() == 0) {//leaving express line 

				output = Ex.dequeue();
				
				cout << "L: Express ID: " << output.getID() << " Total Time:" << output.getTotal() << "\n";
			}

			if (curWait > 0) {
				curWait--;//reduces wait time if there is wait time 
			}

			if (newEx == i) {//adding to wait line 
				output = Ex.enqueue(id, curWait, 5);
				curWait = curWait + output.getTime();
				id++;
				newEx = newEx + 1 + (rand() % 5);

				cout << "J: Express ID: " << output.getID() << " Time: " << i << " Total Time: " << output.getTotal() << " \n";
			}



			if (Reg.custTime() == 0) {//leaving regular line 

				output = Reg.dequeue();

				cout << "L: Regular " << output.getID() << " " << output.getTotal() << "\n";
			}
			

			if (curWait2 > 0) {// current wait reduces 
				curWait2--;
			}

			if (newReg == i) {//joining regular line
				output = Reg.enqueue(id, curWait2, 6);
				curWait2 = curWait2 + output.getTime();
				id++;
				newReg = newReg + 1 + (rand() % 6);

				cout << "J: Regular " << output.getID() << " Time: " << i << " Total Time: " << output.getTotal() << "\n";
			}





			Reg.min();//decreases a minute of service time for customers in front of their lines 
			Ex.min();



			if ((i % 10) == 0) {//after 24 hours, id numbers are reset to 0



				cout << "Current regular line: ";
				Reg.print();
				cout << "Current express line: "; 
				Ex.print();

			}


			if ((i % 1440) == 0) {//after 24 hours, id numbers are reset to 0

				id = 0;


			}


		}
	
	
	












	
}