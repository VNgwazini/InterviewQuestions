#include <iostream>
#include <string>
#include <vector>
#include <list>
//implement stack that can return min element in 0(1) time

struct Node{
  int key;
  int min;
  Node* next;
  Node(int key){
    this->key = key;
    this->min = NULL;    
    this->next = nullptr;    
  }
};

class Stack{
  private:
    Node* head;
  public:
    Stack(){
      head = nullptr;
    }
    void push(int key){
      Node* temp = new Node(key);
      if(!head){
        temp->min = key;
        head = temp;
      }
      else{
        temp->next = head;
        if(temp->key < head->min){
          temp->min = temp->key;
        }
        else{
          temp->min = head->min;
        }
        head = temp;
      }
    }
    void pop(){
      if(!head){
        return;
      }
      else{
        Node* temp = head->next;
        delete head;
        head = temp;
      }
    }
    int min(){
      std::cout << "The min is: " << head->min << std::endl;
      return head->min;
    }
};

int main(){

  Stack stack;
  stack.push(5);
  stack.push(6);
  stack.push(3);
  stack.push(7);
  stack.min();
  stack.pop();
  stack.min();
  stack.pop();
  stack.min();

  return 0;
}