#include <iostream> 
//calculate the parity of a word

short parity(unsigned long x){
  std::cout << "Parity of " << x << " is: ";
  short result = 0;
  while(x){
    result ^= (x & 1);
    x >>= 1;
  }
  std::cout << result << std::endl;
  return result;
}

int main(){
  unsigned long x = 3;
  parity(x);
  
  return 0;
}