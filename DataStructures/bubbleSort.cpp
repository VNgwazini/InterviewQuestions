#include <iostream>
#include <vector>

void printVector(std::vector<int> &V){
  for(auto it: V){
    std::cout << it << "\t";
  }
  std::cout << std::endl;
}

void bubbleSort(std::vector<int> &V){
  for(int i = 0; i < V.size()-1; i++){
    for(int j = 0; j < V.size()-1-i; j++){
      if(V[j] > V[j+1]){
        std::swap( V[j], V[j+1] );
      }
    }
  }
}

int main(){
  std::vector<int> input = {1,22,33,444,5,66,777,8,99};
  printVector(input);
  bubbleSort(input);
  printVector(input);
  return 0;
}