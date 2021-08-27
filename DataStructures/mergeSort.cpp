#include <iostream>
#include <vector>

void printVector(std::vector<int>& V){
  for(auto it: V){
    std::cout << it << "\t";
  }
  std::cout << std::endl;
}

void merge(std::vector<int>& V, int left, int middle, int right){
  int leftSize = middle - left + 1;
  int rightSize = right - middle;

  std::vector<int> leftArr(leftSize, 0);
  std::vector<int> rightArr(rightSize, 0);

  for(int i = 0; i < leftSize; i++){
    leftArr[i] = V[left+i];
  }
  for(int j = 0; j < rightSize; j++){
    rightArr[j] = V[middle+1+j];
  }

  int leftItr = 0, rightItr = 0, mergeItr = left;

  while(leftItr < leftSize && rightItr < rightSize){
    if(leftArr[leftItr] < rightArr[rightItr]){
      V[mergeItr] = leftArr[leftItr];
      leftItr++;
    } 
    else{
      V[mergeItr] = rightArr[rightItr];
      rightItr++;
    }
    mergeItr++;
  }

  while(leftItr < leftSize){
    V[mergeItr] = leftArr[leftItr];
    leftItr++;
    mergeItr++;
  }

  while(rightItr < rightSize){
    V[mergeItr] = rightArr[rightItr];
    rightItr++;
    mergeItr++;
  }
}

void sort(std::vector<int>& V, int left, int right){
  if(left<right){
    int middle = (left+right)/2;
    sort(V,left,middle);
    sort(V, middle+1, right);
    merge(V,left,middle,right);
  }
}


int main(){
  std::vector<int> input = {1,22,333,4,55,66,777,88,9};
  printVector(input);
  sort(input, 0, input.size()-1);
  printVector(input);
  return 0;
}