#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
//remove duplicates from linked list
struct Node{
  int key;
  Node* next;
  Node(int key){
    this->key = key;
    this->next = nullptr;
  }
};

bool isLoop(std::list<Node*> l){
  if(l.empty()){
    return false;
  }
    std::list<Node*>::iterator it1;
    std::list<Node*>::iterator it2;

    it1 = l.begin();
    it2 = l.begin();
    it2++;

  while(it1 != l.end() && it2 != l.end() ){
    if(*it1 == *it2){
      return true;
    }
    else{
      it1++;
      it2++;
      it2++;
    }
  }
  return false;
}

int main(){
  std::vector< std::list<Node*> > data;
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);

  std::list<Node*> test1;
  test1.push_back(node1);
  test1.push_back(node2);
  test1.push_back(node3);
  test1.push_back(node4);
  test1.push_back(node5);
  test1.push_back(node3);

  std::list<Node*> test2;
  test2.push_back(node1);
  test2.push_back(node2);
  test2.push_back(node3);
  test2.push_back(node4);
  test2.push_back(node5);

  data.push_back(test1);
  data.push_back(test2);

  for(auto it: data){
    try{
      throw isLoop(it);
    }
    catch(bool result){
      for(auto i: it){
        std::cout << "(" << i->key << ")-->";
      }
      if(result){
        std::cout << " is a loop!\n";
      }
      else{
        std::cout << " is NOT a loop!\n";
      }
    }
  }
  return 0;
}