#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
//see if string is palindrome

std::vector<int> intersect( std::vector<int> &v1, std::vector<int> &v2){
  std::vector<int> result;
  // //O(n*m) 
  // std::vector<int>::iterator it;
  // for(int i = 0; i < v1.size(); i++){
  //   it = std::find( v2.begin(), v2.end(),v1[i]);
  //   if(it != v2.end()){
  //     result.push_back(*it);
  //   }
  // }
  // //0(n)
  int itr1 = 0, itr2 = 0;
  int v1Size = v1.size(), v2Size = v2.size();

  while(itr1 < v1Size && itr2 < v2Size){
    if(v1[itr1] < v2[itr2]){
      itr1++;
    }
    else if(v1[itr1] > v2[itr2]){
      itr2++;
    }
    else{
      result.push_back(v1[itr1]);
      itr1++;
    }
  }

  return result;
}

std::vector<int> startHere( std::vector<int> &v1,  std::vector<int> &v2){
  if(v1.size() <= v2.size()){
    return intersect(v1,v2);
  }
  else{
    return intersect(v2,v1);
  }
}


void printVector(std::vector<int> input){
  for(auto it: input){
    std::cout << it << "\t";
  }
}

int main(){
  std::vector<int> v1 {1,2,3,4,5,6};
  std::vector<int> v2 {2,3,5,7};
  std::vector<int> expected {2,5};

  try{
    throw startHere(v1,v2);
  }
  catch(std::vector<int> result){
    printVector(v1);
    std::cout << " and \t";
    printVector(v2);
    std::cout << " intersect at: ";
    printVector(expected);
    std::cout << std::endl;
  }

  return 0;
}