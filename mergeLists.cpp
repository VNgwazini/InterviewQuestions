#include <iostream>
#include <vector>
//merge two lists

std::vector<int> merge(std::vector<int> v1, std::vector<int> v2){
  int p1 = 0, p2 = 0;
  std::vector<int> result;

  while(p1 < v1.size() && p2 < v2.size()){
    if(v1[p1] < v2[p2]){
      result.push_back(v1[p1]);
      p1++;
    }
    else{
      result.push_back(v2[p2]);
      p2++;
    }
  }
  
  while(p1 < v1.size()){
    result.push_back(v1[p1]);
    p1++;
  }

  while(p2 < v2.size()){
    result.push_back(v2[p2]);
    p2++;
  }

  return result;
}

void printVector(std::vector<int> input){
  for(auto it: input){
    std::cout << it << ", ";
  }
}

int main(){
  std::vector<int> v1 {2,5,8,11,14};
  std::vector<int> v2 {1,3,5,7};
  std::vector<int> result;

  result = merge(v1,v2);
  printVector(v1);
  std::cout << " merged with ";
  printVector(v2);
  std::cout << " becomes ";
  printVector(result);
  std::cout << std::endl;

  return 0;
}