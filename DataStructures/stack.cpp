#include <iostream>

struct Node{
  int key;
  int min;
  Node* next;
  Node(int key){
    this->key = key;
    this->next = nullptr;
  }
};

class Stack{
  private:
    Node* head;
    int size;
    int min;
  public:
    Stack(){
      head = nullptr;
      size = 0;
      min = 0;
    }

    int getMin(){
      if(!head){
        return -1;
      }
      else{
        std::cout << "The min is: " << head->min << "\n============" << std::endl;
        return head->min;
      }
    }

    int getSize(){
      if(!head){
        return -1;
      }
      else{
        std::cout << "The size is: " << size << std::endl;
        return size;
      }    
    }

    bool isEmpty(){
      head == nullptr?std::cout << "Is empty!\n":std::cout << "Not empty\n";
      return head == nullptr;
    }

    void push(int key){
      Node* temp = new Node(key);
      if(!head){
        temp->min = temp->key;
        head = temp;
      }
      else{
        if(temp->key < head->min){
          temp->min = temp->key;
        }
        else{
          temp->min = head->min;
        }
        temp->next = head;
        head = temp;
      }
      size++;
      getSize();
      isEmpty();
      top();
      getMin();
    }

    int top(){
      if(!head){
        return -1;
      }
      else{
        int top = head->key;
        std::cout << "The top is: " << head->key << std::endl;
        return top;
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
        size--;
        getSize();
        isEmpty();
        top();
        getMin();
      }
    }
};

int main(){
  Stack s;
  s.push(3);
  s.push(4);
  s.push(7);
  s.push(5);
  s.push(2);
  s.push(1);
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
}