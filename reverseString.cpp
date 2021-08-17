#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//reverse a string

void swap(std::string &s, int a, int b){
  int temp = s[a];
  s[a] = s[b];
  s[b] = temp; 
}

std::string reverseString(std::string str){
  int l = 0, r = str.length()-1;
  while(l < r){
    swap(str, l, r);
    l++;
    r--;
  }
  return str;
}

int main(){
  std::vector<std::string> data;
  data.push_back("ABC");
  data.push_back("A B C"); 
  data.push_back("ABCD");
  data.push_back("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG");


  for(auto it: data){
    try{
      throw reverseString(it);
    }
    catch(std::string result){
      std::cout << it << " is now " << result << std::endl;
    }
  }
  return 0;
}