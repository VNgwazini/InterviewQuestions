#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>

//see if string b is a permutation of string a
bool isPermutation(std::string A, std::string B){
  if(A.length() != B.length()){
    return false;
  }
  else{
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    for(int i = 0; i < A.length(); i++){
      if(A[i] != B[i]){
        return false;
      }
    }
    return true;
  }
}

int main(){
  std::vector<std::string> data;
  data.push_back("cba");
  data.push_back("xyz");

  for(auto it: data){
    try{
      throw isPermutation("abc",it);
    }
    catch(bool result){
      if(result){
        std::cout << it << " is permutation of abc!\n";
      }
      else{
        std::cout << it << " is NOT permutation of abc!\n";
      }
    }
  }
  return 0;
}