#include <iostream>
#include <string>
#include <vector>
#include <list>
//remove duplicates from linked list

std::list<int> sumList(std::list<int> &a, std::list<int> &b){
  std::list<int> result;
  std::string s1, s2;

  for(auto it: a){
    s1.push_back(it+'0');
  }
  for(auto it: b){
    s2.push_back(it+'0');
  }

  int num1 = std::stoi(s1);
  int num2 = std::stoi(s2);
  int sum1 = num1 + num2;
  std::string sumStr = std::to_string(sum1);

  for(int i = sumStr.length()-1; i >= 0; i--){
    int digit = sumStr[i]-'0';
    result.push_front(digit);
  }
  return result;
}

int main(){
  std::vector< std::list<int> > data;

  std::list<int> stack1;
  stack1.push_front(8);
  stack1.push_front(2);
  stack1.push_front(5);

  std::list<int> stack2;
  stack2.push_front(4);
  stack2.push_front(9);
  stack2.push_front(2);

  try{
    throw sumList(stack1, stack2);
  }
  catch(std::list<int> result){
    for(auto it: stack1){
      std::cout << it;
    }
    std::cout << " + ";
    for(auto it: stack2){
      std::cout << it;
    }
    std::cout << " = ";
    for(auto it: result){
      std::cout << it;
    }
    std::cout << std::endl;
  }
  return 0;
}