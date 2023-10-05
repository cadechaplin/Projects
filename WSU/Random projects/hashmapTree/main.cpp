#include "hashmap.h"
#include <string.h>
int main(){
    
    hashmap<std::string> myMap(10);

    myMap.insert("Cade",0); 
    myMap.insert("Nash",0); 
    myMap.insert("Hunter",0); 


    myMap.insert("Cad",1); 
    myMap.insert("Nas",1); 
    myMap.insert("Hunte", 11); 

    cout << "should be 1: " << myMap.find("Cade",0) << endl;
    cout << "should be 1: " << myMap.find("Nash",0) << endl;
    cout << "should be 1: " << myMap.find("Hunter",0) << endl;
    cout << "should be 1: " << myMap.find("Hunte", 11) << endl;
    cout << "should be 1: " << myMap.find("Nas",1) << endl;
    cout << "should be 1: " << myMap.find("Cad",1) << endl;

    cout << "should be 1: " << myMap.find("Cade",1) << endl;
    cout << "should be 1: " << myMap.find("Nash",2) << endl;
    cout << "should be 1: " << myMap.find("Hunter",4) << endl;
    cout << "should be 1: " << myMap.find("Hunte", 5) << endl;
    cout << "should be 1: " << myMap.find("Nas",6) << endl;
    cout << "should be 1: " << myMap.find("Cad",3) << endl;
    /*
    myMap.insert(0,10);
    myMap.insert(1,11);
    myMap.insert(2,12);
    myMap.insert(3,13);

    myMap.insert(0,10);
    myMap.insert(0,10);
    myMap.insert(0,10);
    myMap.insert(0,10);
    myMap.insert(0,20);

    cout << "should be 1: " << myMap.find(0,10) << endl;
    cout << "should be 0: " << myMap.find(1,10) << endl;


    myMap.insert(4,10);
    myMap.insert(5,21);
    myMap.insert(6,12);
    myMap.insert(7,13);

    myMap.insert(9,31);

    myMap.insert(10,41);

    cout << "should be 1: " <<myMap.find(7,13) << endl;
    cout << "should be 1: " << myMap.find(1,11) << endl;
    cout << "should be 0: " <<myMap.find(18,13) << endl;
    
    */

return 0;

}


