
#include "list.h"
#include <vector>




template <class T>
class hashmap : public Node<T> {
public:
    
    hashmap(int val = 10);
    hashmap(Node<T>* mList,int val = 0);
    ~hashmap();
    
    void insert(T data, int hashval);
   
    bool isMap();
    bool find(T data, int val);
    
    
private:
    std::vector <Node<T>*> map;
    
};

template <class T>
hashmap<T>::hashmap(int size) {
    if (size <= 0) {
            throw std::invalid_argument("Value must be a positive integer.");
        }
    this->map.resize(size);
  
    
}
template <class T>
hashmap<T>::hashmap(Node<T>* mList, int size) {
    this->map.resize(size);
    this->map[mList->slotVal() % map.size()] = mList;
  
    
}
template <class T>
hashmap<T>::~hashmap() {
    //elete this->map;
    
}



template <class T>
void hashmap<T>::insert(T data, int val) {
    int hashval = val % (this->map.size() );
    if((this->map)[hashval] == nullptr){
        (this->map)[hashval] = new List<T>(val);
        (this->map)[hashval]->insert(data, val);
        return;

    }
    if((this->map)[hashval]->isList() && (this->map)[hashval]->slotVal() != val){
        hashmap* nMap = new hashmap(this->map[hashval], this->map.size() + 1);
        nMap->insert(data,val);
        this->map[hashval] = nMap;
        return;
    }
    this->map[hashval]->insert(data, val);
    return;
    
}



template <class T>
bool hashmap<T>::isMap(){
return true;

}

template<class T>
bool hashmap<T>::find(T data, int val){
    int hashvalue = val % this->map.size();
    if (this->map[hashvalue] == nullptr){
        return false;
    }
    return (this->map[hashvalue]->find(data,val));



}