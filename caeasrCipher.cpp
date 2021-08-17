#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//see if string is palindrome

std::string caesarCipher(std::string str, const int shift){
  for(int i = 0; i < str.length(); i++){
    if(str[i] == ' '){
      continue;
    }
    else if((str[i] - shift) < 'A'){
      str[i] += 23;
    }
    else{
      str[i] -= shift;
    }
  }
  return str;
}

int main(){
  std::vector<std::string> data;
  data.push_back("ABC");
  data.push_back("A B C"); 
  data.push_back("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG");


  for(auto it: data){
    try{
      throw caesarCipher(it,3);
    }
    catch(std::string result){
      std::cout << it << " is now " << result << std::endl;
    }
  }
  return 0;
}