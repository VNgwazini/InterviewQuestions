#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
//remove duplicates from linked list

std::list<int> removeDuplicates(std::list<int> &l){
  std::list<int>::iterator it;
  it = l.begin();
  std::unordered_map<int, bool> visited;

  while(it != l.end()){
    if(!visited[*it]){
      visited[*it] = true;
    }
    else{
      l.erase(it);
    }
    it++;
  }

  return l;
}

int main(){
  std::vector< std::list<int> > data;
  std::list<int> test1;
  test1.push_back(1);
  test1.push_back(2);
  test1.push_back(1);

  data.push_back(test1);

  for(auto it: data){
    try{
      throw removeDuplicates(it);
    }
    catch(std::list<int> result){
      for(auto i: it){
        std::cout << "(" << i << ")\n";
      }
    }
  }
  return 0;
}