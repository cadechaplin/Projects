#include "node.h"
#include <vector>
template <class F>
class List : public Node<F> {
public:

    List(int val);
    ~List();
    std::vector<F> data;
    int hashvalue;
    void insert(F data, int val);
    void insert(F data);
    bool isList();
    int slotVal();
    bool find(F data, int val);
    
};

template <class F>
List<F>::List(int val){
this->hashvalue = val;
    
};


template <class F>
List<F>::~List(){};

template <class F>
void List<F>::insert(F data, int val){
this->data.push_back(data);



}
template <class F>
void List<F>::insert(F data){
this->data.push_back(data);



}
template <class F>
bool List<F>::isList(){
return true;

}

template<class F>
int List<F>::slotVal(){
return this->hashvalue;



}

template<class F>
bool List<F>::find(F data, int val){

if(this->hashvalue != val){
    return false;
}

for(int i = 0; i < this->data.size(); i++){
    if(this->data[i] == data){
        return true;
    }

}


return false;



}