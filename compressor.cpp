#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list> 
//compress string 

std::string compressor(std::string &s){
  std::list<char> order;
  std::unordered_map<char, int> visited;
  for(int i = 0; i < s.length(); i++){
    if(!visited[s[i]]){
      order.push_back(s[i]);
      visited[s[i]];
    }
    visited[s[i]]++;
  }

  std::string result(order.size()*2, ' ');
  int index = 0;
  for(auto it: order){
    result[index] = it;
    result[index+1] = visited[it]+'0';
    index += 2;
  }
  if(result.size() < s.size()){
    return result;
  }
  else{
    return s;
  }
}

int main(){
  std::vector<std::string> data;
  data.push_back("aaabb");
  data.push_back("aabb");

  for(auto it: data){
    try{
      throw compressor(it);
    }
    catch(std::string result){
      std::cout << it << " is now " <<result << std::endl;
    }
  }
  return 0;
}