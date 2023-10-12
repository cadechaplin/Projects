#include "AVLTree.h"
#include "hashmap.h"
#include <string.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>


class test{
public:
test();
~test();
void setValCount(int count);
void buildVector();
void clearData();
void toggleRandom();
void fillAVL();
void fillHashMap();
void setDataMax(int val);
void setDataMin(int val);
void runtest();

private:
hashmap<int> Map;
AVLTree <int> AVL;
vector<int> nums;
int dataMax, dataMin;
bool rand;
int dataCount;



};