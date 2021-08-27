#include <iostream>

class MaxHeap{
  private:
    int *arr;
    int size;
    int capacity;

    int parentIndex(int index){
      return (index - 1)/2;
    }
    int leftIndex(int index){
      return (index * 2) + 1;
    }
    int rightIndex(int index){
      return (index * 2) + 2;
    }

    bool hasParent(int index){
      return parentIndex(index) >= 0;
    }
    bool hasLeft(int index){
      return leftIndex(index) < size;
    }
    bool hasRight(int index){
      return rightIndex(index) < size;
    }

    int getParent(int index){
      return arr[parentIndex(index)];
    }
    int getLeft(int index){
      return arr[leftIndex(index)];
    }
    int getRight(int index){
      return arr[rightIndex(index)];
    }

    void ensureCapacity(){
      if(size == capacity){
        int *temp = new int[2*capacity];
        for(int i = 0; i < capacity; i++){
          if(i < size){
            temp[i] = arr[i];
          }
          else{
            temp[i] = '\000';
          }
        }
        delete arr;
        arr = temp;
        capacity *= 2;
      }
    }

      void heapifyUp(){
        int index = size-1;
        while(hasParent(index) && arr[index] > getParent(index)){
          std::swap(arr[index],arr[parentIndex(index)]);
          index = parentIndex(index);
        }
      }
      void heapifyDown(){
        int index = 0;
        while(hasLeft(index)){
          int largestChildIndex = leftIndex(index);
          if(hasRight(index) && getRight(index) > arr[largestChildIndex]){
            largestChildIndex = rightIndex(index);
          }
          if(arr[index] > arr[largestChildIndex]){
            break;
          }
          else{
            std::swap(arr[index], arr[largestChildIndex]);
            index = largestChildIndex;
          }
        }
      }
  public:
    MaxHeap(int initCapacity){
      arr = new int[initCapacity];
      size = 0;
      capacity = initCapacity;
    }
    void push(int key){
      ensureCapacity();
      arr[size] = key;
      size++;
      heapifyUp();
      print();
    }
    int popMax(){
      int max = arr[0];
      std::swap(arr[0], arr[size-1]);
      size--;
      heapifyDown();
      print();
      return max;
    }
    void print(){
      for(int i = 0; i < size; i++){
        std::cout << "[" << arr[i] << "]\n";
      }
      std::cout << "=============\n";
    }
};

int main(){
  MaxHeap h(3);
  h.push(10);
  h.push(7);
  h.push(15);
  h.push(5);
  h.push(25);
  h.push(38);
  h.popMax();
  h.popMax();
  h.popMax();
  h.popMax();
  h.popMax();
  return 0;
}