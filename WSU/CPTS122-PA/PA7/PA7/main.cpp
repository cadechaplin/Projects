


#include "System.h"

/*
Cade Chaplin 
PA7
This program is for recording abcences. It has classes node, list, and array stack, that I inplemented using templates. The class Record is not a template and is used to store student data. 
This program can take student information from the class list, doing so will clear the classlist csv and stored in the master csv so that the same data cannot be placed into the list twice. 
Since the classlist csv does not contain information about prior abecenses, when the information is placed in the list, the stack of abecenses is empty. 
The way I save to the master list saves the amount of absences, followed by each date the student was absence, so when the program loads from the master, it will also load prior absences, which 
is something the classList csv could not do.
When an abence is marked, a string containing the days date is added to the stack inside of the record for the given student. 
When the abences are edited, the stack is emptied into another stack, and if the data the has been requested to remove matches the data the is being removed from the preremoved stack is not added to 
the new stack, then the old stack is copied over by the new stack inside of the node.
I have put the programs functions inside class system, with only one public function which is run(), and the other functions are reached through the menu that run() brings up.



*/

int main() {


	

    // Need this:
    System mainFrame;

    mainFrame.run();
    

	return 0;
}