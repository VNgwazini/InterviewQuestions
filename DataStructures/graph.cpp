#include <iostream>
#include <list>

class Graph{
  private:
    int verticies;
    std::list<int> **adjList;
  public:
    Graph(int V){
      verticies = V;
      adjList = new std::list<int>*[V];
      for(int i = 0; i < verticies; i++){
        adjList[i] = new std::list<int>;
      }
    }
    void addEdge(int v, int w){
      adjList[v]->push_back(w);
    }
    void printBFS(int v){
      bool *visited = new bool[verticies];
      for(int i = 0; i < verticies; i++){
        visited[i] = false;
      }
      std::list<int> queue;
      queue.push_back(v);
      while(!queue.empty()){
        v = queue.front();
        std::cout << v << "\t";
        queue.pop_front();
        std::list<int>::iterator it;
        it = adjList[v]->begin();
        while(it != adjList[v]->end()){
          if(!visited[*it]){
            visited[*it] = true;
            queue.push_front(*it);
          }
          it++;
        }
      }
      std::cout << std::endl;
    }
};

int main(){
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.printBFS(2);
}