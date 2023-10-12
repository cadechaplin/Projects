#include "test.h"
test::test(){
dataMin = 0;
dataMax = 0;
rand = false;


};
test::~test(){
};

void test::buildVector(){
    clearData();
    std::uniform_int_distribution<int> dist(dataMin, dataMax);
    std::random_device rd;//generating random number
    std::mt19937 gen(rd());
    for(int i = 0; i <= dataCount; i++){
        if(!rand){

            this->nums.push_back(i+dataMin);
        
        }
        else{

        this->nums.push_back(dist(gen));
        }

    }
};
void test::toggleRandom(){
if(rand){
    rand = false;
    return;
}
rand = true;
};
void test::clearData(){
    nums.clear();
    AVL.~AVLTree();
    AVL = *(new AVLTree<int>);
    Map.~hashmap();
    Map = *(new hashmap<int>);

}
void test::fillAVL(){
for(int i = 0; i < nums.size(); i++){
    AVL.insert(nums[i]);

}


};
void test::fillHashMap(){

for(int i = 0; i < nums.size(); i++){
    Map.insert(nums[i],nums[i]);

}

};
void test::setDataMax(int val){
dataMax = val;
};
void test::setDataMin(int val){

dataMin = val;
};
void test::setValCount(int val){

    
dataCount = val;
}
void test::runtest(){
    this->buildVector();
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){//inserting in random order
        AVL.insert(nums[i]);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto AVLFillDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function AVL-insert on " << dataCount <<  " non unique: " << AVLFillDuration.count() << " microseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){//inserting in random order
        Map.insert(nums[i], nums[i]);
    }
    stop = std::chrono::high_resolution_clock::now();
    auto HashmapTreeFillDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function hashmap-insert on " << dataCount <<  " non unique: " <<  HashmapTreeFillDuration.count() << " microseconds" << std::endl;

    
    start = std::chrono::high_resolution_clock::now();
    AVL.contains(nums[1]);
    stop = std::chrono::high_resolution_clock::now();
    auto AVLFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function AVL-contains: " << AVLFindDuration.count() << " nanoseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    Map.find(nums[1],nums[1]);
    stop = std::chrono::high_resolution_clock::now();
    auto HashmapTreeFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function Map-find: " << HashmapTreeFindDuration.count() << " nanoseconds" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    AVL.contains(-1);
    stop = std::chrono::high_resolution_clock::now();
    AVLFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function AVL-contains for value not in tree: " << AVLFindDuration.count() << " nanoseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();
    Map.find(-1,-1);
    stop = std::chrono::high_resolution_clock::now();
    HashmapTreeFindDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Time taken by function Map-find for value not in map: " << HashmapTreeFindDuration.count() << " nanoseconds" << std::endl;


};