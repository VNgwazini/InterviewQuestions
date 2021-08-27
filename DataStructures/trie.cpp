#include <iostream>
#include <string> 

const int ALPHA = 26;

struct Node{
  Node* children[ALPHA];
  bool endOfString;
  Node(){
    this->endOfString = false;
    for(int i = 0; i < ALPHA; i++){
      this->children[i] = nullptr;
    }
  }
};

class Trie{
  public:
    void insert(Node* node, std::string key){
      Node* itr = node;
      for(int i = 0; i < key.length(); i++){
        int index = key[i] -'a';
        if(!itr->children[index]){
          itr->children[index] = new Node();
        }
        itr = itr->children[index];
      }
      itr->endOfString = true;
    }

    bool search(Node* node, std::string key){
      Node* itr = node;
      for(int i = 0; i < key.length(); i++){
        int index = key[i] -'a';
        if(!itr->children[index]){
          std::cout << key << " was NOT found\n";
          return false;
        }
        itr = itr->children[index];
      }
      std::cout << key << " was found!\n";
      return (itr && itr->endOfString);
    }

    bool isEmpty(Node* node){
      for(int i = 0; i < ALPHA; i++){
        if(node->children[i]){
          return false;
        }
      }
      return true;
    }

    Node* remove(Node* node, std::string key, int depth = 0){
      if(!node){
        return nullptr;
      }
      if(depth == key.length()){
        if(node->endOfString){
          node->endOfString = false;
        }
        if(isEmpty(node)){
          delete node;
          node = nullptr;
        }
        return node;
      }
      int index = key[depth] - 'a';
      node->children[index] = remove(node->children[index], key, depth+1);
      if(isEmpty(node) && !node->endOfString){
        delete node;
        node = nullptr;
      }
      return node;
    }

};

int main(){
  Trie t;
  Node* root = new Node();
  t.insert(root, "the");
  t.insert(root, "their");
  t.insert(root, "there");
  t.insert(root, "these");
  t.insert(root, "by");
  t.insert(root, "bye");
  t.insert(root, "a");
  t.insert(root, "any");
  t.search(root, "the");
  t.search(root, "these");
  t.search(root, "those");
  t.search(root, "bye");
}