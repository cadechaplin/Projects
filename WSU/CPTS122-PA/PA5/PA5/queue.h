#pragma once

#include "node.h"



class Queue

{

public: // Member functions

    Queue(Node* newpHead = nullptr, Node* newpTail = nullptr);

    Data enqueue(int id, int time, int line);//adds new customer to que

    void min();//reduces minute from service time for customer at beginning of line 

    int custTime();

    Data dequeue();//removes node from queue and returns data from the node removed 

    void leftOver();// wasnt used in the program but this just gets rid of all nodes in queue 

    Node* getHead();//gets head pointer 

    ~Queue();

    void print();

    void printQ(Node * pCUr);

private:

    Node* pHead;

    Node* pTail;

    void destroyQueue();

    bool isEmpty();
};