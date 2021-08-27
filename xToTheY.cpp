#include <iostream> 
//calculate the x to the y

double power(double x, int y){
  std::cout << x << "^" << y << " = ";
  double result = 1.0;
  long long power = y;

  if(y < 0){
    power = -power;
    x = 1.0/x;
  }

  while(power){
    if(power & 1){
      result *= x;
    }
    x *= x;
    power >>= 1;
  }
  std::cout << result << std::endl;
  return result;
}

int main(){
  unsigned long x = 3;
  power(2.0,3);
  
  return 0;
}