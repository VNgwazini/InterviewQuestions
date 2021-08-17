#include <iostream>

void fizzbuzz(){
  for(int i = 1; i < 101; i++){
    if(i%3 != 0 && i%5 != 0){
      std::cout << i;
    }
    if(i%3 == 0){
      std::cout << "Fizz";
    }    
    if(i%5 == 0){
      std::cout << "Buzz";
    }
    std::cout << std::endl;
  }
}

int main(){
  fizzbuzz();

  return 0;
}