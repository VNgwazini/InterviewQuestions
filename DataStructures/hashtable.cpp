#include <iostream>
#include <list>

class HashTable{
  private:
    int buckets;
    int size;
    std::list<int> *table;
  public:
    HashTable(int initBuckets){
      buckets = initBuckets;
      size = 0;
      table = new std::list<int>[buckets];
    }
    int hashFunction(int key){
      return key % buckets;
    }
    void insert(int key){
      int index = hashFunction(key);
      table[index].push_back(key);
      size++;
      print();
    }
    void remove(int key){
      int index = hashFunction(key);
      std::list<int>::iterator it;
      it = table[index].begin();
      while(it != table[index].end()){
        if(*it == key){
          table[index].erase(it);
          break;
        }
        else{
          it++;
        }
      }
      print();
    }
    void print(){
      std::cout << "HashTable:\n";
      for(int i = 0; i < buckets; i++){
        std::cout << "[" << i << "]";
        for(auto it: table[i]){
          std::cout << it << "-->";
        }
        std::cout << std::endl;
      }
      std::cout << "=================\n";
    }
};

int main(){
  HashTable t(3);
  t.insert(1);
  t.insert(22);
  t.insert(333);
  t.insert(44);
  t.insert(5);
  t.insert(66);
  t.insert(777);
  t.insert(88);
  t.remove(333);
  t.remove(1);
  t.remove(5);

  return 0;
}