#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
//see if string is an anagram of the other

bool isAnagram(std::string s1, std::string s2){
  if(s1.length() != s2.length()){
    return false;
  }

  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  if(s1 == s2){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  std::vector<std::string> data;
  data.push_back("arc");
  data.push_back("crap");


  for(auto it: data){
    try{
      throw isAnagram("car",it);
    }
    catch(bool result){
      if(result){
        std::cout << it << " is an anagram!\n";
      }
      else{
        std::cout << it << " is NOT an anagram!\n";
      }
    }
  }

  return 0;
}