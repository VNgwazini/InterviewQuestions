#include <iostream>
#include <vector>


typedef enum { RED, WHITE, BLUE} Color;

void printColors(std::vector<Color> colors){
  for(int i = 0; i < colors.size(); i++){
    std::cout << colors[i] << "\t";
  }
  std::cout << std::endl;
}

void dutchFlag(int pivot_index, std::vector<Color>* aPtr){
  std::vector<Color>& A = *aPtr;
  Color pivot = A[pivot_index];

  int smaller = 0, equal = 0, larger = A.size() - 1;
  //equal is the index of the unsorted item
  while(equal < larger){
    if(A[equal] < pivot){
      std::swap(A[smaller++], A[equal++]);
    }
    else if(A[equal] == pivot){
      ++equal;
    }
    else{
      std::swap(A[equal], A[--larger]);
    }
    printColors(A);
  }
}

int main(){
  std::vector<Color> colors {WHITE, RED, RED, WHITE, WHITE, BLUE, BLUE, RED, BLUE};
  printColors(colors);
  dutchFlag(colors.size()/2, &colors);
  printColors(colors);
}