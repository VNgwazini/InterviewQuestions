#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//see if string is palindrome

bool isRansom(const std::string &s1, const std::string &s2){
  std::unordered_map<char,int> visited1, visited2;

  for(int i = 0; i < s1.length(); i++){
    if(s1[i] != ' '){
      visited1[s1[i]]++;
    }
  }
  for(int i = 0; i < s2.length(); i++){
    if(s2[i] != ' '){
      visited2[s2[i]]++;
    }
  }

  std::unordered_map<char,int>::iterator it1;
  it1 = visited1.begin();

  while(it1 != visited1.end()){
    if(!visited2[it1->first]){
      return false;
    }
    else if(visited2[it1->first]<visited1[it1->first]){
      return false;
    }
    else{
      it1++;
    }
  }
  return true;
}

int main(){
  std::vector<std::string> data;
  data.push_back("yaP");
  data.push_back("yaP a");
  // data.push_back("ayPem0001$");
  data.push_back("pa");


  for(auto it: data){
    try{
      throw isRansom("Pay",it);
    }
    catch(bool result){
      if(result){
        std::cout << it << " is a ransom of Pay!\n";
      }
      else{
        std::cout << it << " is NOT a ransom of Pay!\n";
      }
    }
  }

    try{
      throw isRansom("Pay me $1000", "ayPem0001$");
    }
    catch(bool result){
      if(result){
        std::cout << "ayPem0001$ is a ransom of Pay me $1000!\n";
      }
      else{
        std::cout <<"ayPem0001$ is NOT a ransom of Pay me $1000!\n";
      }
    }

  return 0;
}