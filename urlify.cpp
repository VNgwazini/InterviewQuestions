#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
//replace spaces in string with %20

std::string urlify(std::string &str, int final_length){
  //remove leading spaces
  std::size_t endPos = str.find_first_not_of(' ');
  if(endPos != std::string::npos){
    if(str[0] == ' '){
      str.erase(0,endPos);
    }
  }
  //remove trailing spaces
  std::size_t startPos = str.find_last_not_of(' ');
  if(startPos != std::string::npos){
    str.erase(startPos+1);
  }
  std::string result(final_length, ' ');
  int resultItr = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[i] != ' '){
      result[resultItr] = str[i];
      resultItr++;
    }
    else{
      result[resultItr] = '%';
      result[resultItr+1] = '2';
      result[resultItr+2] = '0';
      resultItr += 3;
    }
  }
  return str = result;
}

int main(){
  std::vector<std::string> data;
  data.push_back("My Home Page     ");

  for(auto it: data){
    try{
      throw urlify(it,16);
    }
    catch(std::string result){
      std::cout << "(My Home Page    ) is now (" << result << ")\n";
    } 
  }
  return 0;
}