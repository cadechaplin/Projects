#pragma once
#include "data.h"

class Node

{

public: // Member functions
    Node(int id, int time, int line);//makes node
    ~Node();

    void setNextPtr(Node* newNextPtr);

    void min();

    int custTime();

    int getID();

    Node* getNext();

    Data getData();

private:

    Data* pData;    // The memory for Data will need to be allocated on the heap as well!

    Node* pNext;

};