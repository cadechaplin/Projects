#pragma once

#include <iostream>
#include <cstdlib>
#include <ostream>


using std::cout;
using std::cin;

class Data

{

public: // Member functions
    Data();
    Data(int id, int time, int line);


    Data operator= (Data rhs);

    void min();

    int getTime();

    int getID();

    int getTotal();

    

private:

    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1

    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes

    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes



};


