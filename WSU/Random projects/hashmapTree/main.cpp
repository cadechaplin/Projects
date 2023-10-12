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


#include "test.h"

int main(){
    
    test myTest;
    myTest.toggleRandom();
    myTest.setDataMax(10000);
    myTest.setDataMin(0);
    myTest.setValCount(100000);
    myTest.fillAVL();
    myTest.fillHashMap();
    myTest.clearData();
    myTest.runtest();
    //std::shuffle(nums.begin(), nums.end(), gen);//shuffling

    /*
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

*/
return 0;

}


