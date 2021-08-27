#include <iostream>
#include <vector>

void printVector(std::vector<int>& V){
  for(auto it: V){
    std::cout << it << "\t";
  }
  std::cout << std::endl;
}
int partition(std::vector<int>& V, int left, int pivot, int right){
  while(left <= right){
    while(V[left] < pivot){
      left++;
    }
    while(V[right] > pivot){
      right--;
    }
    if(left <= right){
      std::swap(V[left], V[right]);
      left++;
      right--;
    }
  }
  return left;
}

void sort(std::vector<int>& V, int left, int right){
  if(left>=right){
    return;
  }
  int pivot = V[(left+right)/2];
  int partitonIndex = partition(V, left, pivot, right);
  sort(V, left, partitonIndex-1);
  sort(V, partitonIndex, right);
}


int main(){
  std::vector<int> input = {1,22,333,4,55,66,777,88,9};
  printVector(input);
  sort(input, 0, input.size()-1);
  printVector(input);
}