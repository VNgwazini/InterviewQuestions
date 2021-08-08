#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//see if string contains only unique characters

bool isUnique(const std::string &str){
  std::unordered_map<char,bool> visited;
  for(int i = 0; i < str.length(); i++){
    if(visited[str[i]]){
      return false;
    }
    else{
      visited[str[i]] = true;
    }
  }
  return true;
}

int main(){
  std::vector<std::string> data;
  data.push_back("abc");
  data.push_back("aa");

  for(auto it: data){
    try{
      throw isUnique(it);
    }
    catch(bool result){
      if(result){
        std::cout << it << " is unique!\n";
      }
      else{
        std::cout << it << " is NOT unique!\n";
      }
    }
  }
  return 0;
}