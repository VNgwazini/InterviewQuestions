#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//see if string is palindrome

bool isPalindrome(const std::string &str){
  int l = 0;
  int r = str.length()-1;

  while(l <= r){
    if(str[l] != str[r]){
      return false;
    }
    l++;
    r--;
  }
  return true;
}

int main(){
  std::vector<std::string> data;
  data.push_back("dad");
  data.push_back("dog");
  data.push_back("abba");
  data.push_back("abbc");


  for(auto it: data){
    try{
      throw isPalindrome(it);
    }
    catch(bool result){
      if(result){
        std::cout << it << " is palindrome!\n";
      }
      else{
        std::cout << it << " is NOT palindrome!\n";
      }
    }
  }
  return 0;
}