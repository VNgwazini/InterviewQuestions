#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int> > matrix){
  for(auto row: matrix){
    for(auto column: row){
      std::cout << column  << "\t";
    }
    std::cout << "\n\n";
  }
}

void printSpiralMatrix(std::vector<std::vector<int> > matrix){

}
int main(){
  std::vector<std::vector<int> > matrix = {{1,2,3},{8,9,4},{7,6,5}};
  printMatrix(matrix);
  return 0;
}