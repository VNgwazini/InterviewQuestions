#include <iostream>

class Array{
  private:
    int *arr;
    int size;
    int capacity;
  public:
    Array(int initialCap){
      arr = new int[initialCap];
      size = 0;
      capacity = initialCap;
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
    int getSize(){
      std::cout << "size is: " << size << std::endl;
      return size;
    }
    void push_back(int value){
      ensureCapacity();
      arr[size] = value;
      size++;
      print();
    }
    void insert(int value, int index){
      ensureCapacity();
      for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
      }
      arr[index] = value;
      size++;
      print();
    }
    void remove(int value, int index){
      for(int i = index; i <= size-1; i++){
        arr[i] = arr[i+1];
      }
      arr[size] = '\000';
      size--;
      print();
    }
    void pop_back(){
      arr[size-1] = '\000';
      size--;  
      print();
    }
    void print(){
      for(int i = 0; i < size; i++){
        std::cout << arr[i] << "\t";
      }
      std::cout << "\n";
    }
};

int main(){
  Array a(1);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.insert(99, 3);
  a.remove(99, 3);
  a.push_back(4);
  a.push_back(5);
  a.pop_back();
  return 0;
}