#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//see if string is palindrome

void swap(std::string &s, int a, int b){
  int temp = s[a];
  s[a] = s[b];
  s[b] = temp; 
}

std::string reverseString(std::string &str){
  int l = 0, r = str.length()-1;
  while(l < r){
    swap(str, l, r);
    l++;
    r--;
  }
  return str;
}

int reverseInt(int input){
  // std::string s = std::to_string(a);
  // if(a < 0){
  //   s.push_back('-');
  // }
  // s = reverseString(s);
  // a = std::stoi(s);

  bool isNegative = (input < 0)? true:false;

  if(isNegative){
    input *= -1;
  }
  
  int answer = 0;
  int lastDigit = 0;

  while(input >= 1){
    lastDigit = input % 10; // to get last digit of input
    answer = answer * 10 + lastDigit; // insert lastdigit to back of answer int
    input /= 10;
  }

  return isNegative == true? answer*-1:answer; //handle negative sign
}


int main(){
  std::vector<int> data;
  data.push_back(123);
  data.push_back(-123); 

  for(auto it: data){
    try{
      throw reverseInt(it);
    }
    catch(int result){
      std::cout << it << " is now " << result << std::endl;
    }
  }
  return 0;
}