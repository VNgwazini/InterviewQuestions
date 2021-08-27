#include <iostream>

struct Node{
  int key;
  Node* next;
  Node(int key){
    this->key = key;
    this->next = nullptr;
  }
};

class Queue{
  private:
    Node* head;
    Node* tail;
  public:
    Queue(){
      head = nullptr;
      tail = nullptr;
    }
    bool isEmpty(){
      return head == nullptr;
    }
    void push(int key){
      Node* temp = new Node(key);
      if(tail){
        tail->next = temp;
      }
      tail = temp;
      if(!head){
        head = tail;
      }
      back();
    }
    int pop(){
      if(!head){
        tail = nullptr;
        return -1;
      }
      else{
        int front = head->key;
        Node* temp = head->next;
        delete head;
        head = temp;
        return front;
      }
      back();
    }

    int front(){
      if(!head){
        return -1;
      }
      else{
        int front = head->key;
        std::cout << "The front is: " << head->key << std::endl;
        return front;
      }
    }

    int back(){
      if(!tail){
        return -1;
      }
      else{
        std::cout << "The back is: " << tail->key << std::endl;
        return tail->key;
      }
    }
};

int main(){
  Queue q;
  q.push(3);
  q.push(4);
  q.push(7);
  q.push(5);
  q.push(2);
  q.push(1);
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  return 0;
}