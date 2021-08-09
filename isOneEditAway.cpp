#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>

//see if string b is one edit away from string a

bool isOneReplace(const std::string &a, const std::string &b){
  bool foundDiff = false;
  for(int i = 0; i < a.length(); i++){
    if(a[i] != b[i]){
      if(foundDiff){
        return false;
      }
      else{
        foundDiff = true;
      }
    }
    return true;
  }
}

bool isOneInsert(const std::string &a, const std::string &b){
  int aItr = 0, bItr = 0;
  while(aItr <  a.length() && bItr < b.length()){
    if(a[aItr] != b[bItr]){
      if(aItr != bItr){
        return false;
      }
      else{
        bItr++;
      }
    }
    else{
      aItr++;
      bItr++;
    }
  }
  return true;
}

bool isOneEditAway(const std::string &a, const std::string &b){
  int aLen = a.length();
  int bLen = b.length();
  if(aLen == bLen){
    return isOneReplace(a,b);
  }
  else if(abs(aLen - bLen)){
    return (aLen < bLen)? 
      isOneInsert(a,b):
      isOneInsert(b,a);
  }
  return false;
}

int main(){
  std::vector<std::string> data;
  data.push_back("pales");
  data.push_back("ple");
  data.push_back("bale");
  data.push_back("bales");


  for(auto it: data){
    try{
      throw isOneEditAway("pale", it);
    }
    catch(bool result){
      if(result){
        std::cout << it << " is one edit away from pale!\n";
      }
      else{
        std::cout << it << " is NOT one edit away from pale!\n";
      }
    }
  }
  return 0;
}