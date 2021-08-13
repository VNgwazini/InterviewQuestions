#include <iostream>
#include <string>
#include <vector>
#include <list>
//implement an infinite stack where if we reach a max height, we add a new stack to the collection. The entire collection must act as a stack

struct Node{
  int key;
  Node* next;
  Node(int key){
    this->key = key;
    this->next = nullptr;    
  }
};

class Stack{
  private:
    std::vector<std::list<int> > stack;
    int threshhold;
  public:
    Stack(int threshhold){
      this->stack = std::vector<std::list<int> >();
      this->threshhold = threshhold;
    }

    void push(int key){
      if(stack.empty() || stack.end()->size() >= threshhold){
        std::list<int> temp;
        temp.push_front(key);
        stack.push_back(temp);
      }
      else{
        int index = stack.size()-1;
        stack[index].push_front(key);
      }
      top();
    }

    void pop(){
      std::list<int> itr;
      int index = stack.size()-1;
      stack[index].pop_front();

      if(stack[index].size() == 0){
        stack.pop_back();
      }
      top();
    }

    int top(){
      std::cout << "Top is: " << stack[stack.size()-1].front() << std::endl;
      return stack[stack.size()-1].front();
    }
};

int main(){

  Stack stack(3);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.pop();
  stack.pop();

  return 0;
}