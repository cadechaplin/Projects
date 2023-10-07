/*
Testing AVL vs my hashmap tree thing for inserting, deleting, and finding.
Implementing Regular BST and hashmap for comparison.
Things to test:
Tightly spread data, loosly spread data, random data 
finding contained numbers, finding non contained numbers

Hypothesis: I believe that using my hashmap tree will complete less recursive loops than the AVL, however I am not sure that this will increase 
real time as I am not sure what the real time lengths of these functions will be. I think that finding will be quicker in the hashmap tree as 
finding does not require the use of moving around memory like adding does, and can index just as fast as the AVL since they both complete one 
mathematical comparison (the hashmap tree does also need a mathematical computation), it just needs less index. 
Results: ???


*/


#include "AVLTree.h"
#include "hashmap.h"
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main(){
    
    hashmap<int> myMap(10);
    AVLTree <int> myAVL;
    vector<int> nums;

    for(int i = 1; i <= 100000000;){//creates vector with all odd numbers between 1-100
        nums.push_back(i);
        i = i +2;
    }

    std::random_device rd;//generating random number
    std::mt19937 gen(rd());
    std::shuffle(nums.begin(), nums.end(), gen);//shuffling
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){//inserting in random order
        myAVL.insert(nums[i]);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto AVLFillDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: " << AVLFillDuration.count() << " microseconds" << std::endl;
    

    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){//inserting in random order
        myMap.insert(nums[i], nums[i]);
    }
    stop = std::chrono::high_resolution_clock::now();
    auto HashmapTreeFillDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: " << HashmapTreeFillDuration.count() << " microseconds" << std::endl;

    
    start = std::chrono::high_resolution_clock::now();
    myAVL.contains(nums[1]);
    stop = std::chrono::high_resolution_clock::now();
    auto AVLFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function: " << AVLFindDuration.count() << " nanoseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    myMap.find(nums[1],nums[1]);
    stop = std::chrono::high_resolution_clock::now();
    auto HashmapTreeFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function: " << HashmapTreeFindDuration.count() << " nanoseconds" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    myAVL.contains(-1);
    stop = std::chrono::high_resolution_clock::now();
    AVLFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function: " << AVLFindDuration.count() << " nanoseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    myMap.find(-1,-1);
    stop = std::chrono::high_resolution_clock::now();
    HashmapTreeFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function: " << HashmapTreeFindDuration.count() << " nanoseconds" << std::endl;
    /*
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
    */
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


