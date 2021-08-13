#include <iostream>
#include <string>
#include <vector>
#include <list>
//deterimine if tree 2 is a substree of tree 1

struct Node{
  int key;
  Node* left;
  Node* right;
  Node(int key){
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class Tree{
  public:
    Node* insert(Node* node, int key){
    if(!node){
      return node = new Node(key);
    }
    else if(key < node->key){
      node->left = insert(node->left, key);
    }
    else {
      node->right = insert(node->right, key);
    }
    return node;
  }
  std::string tree_to_string(Node* node, std::string &target){
    if(!node){
      return target;
    }
    target.push_back(node->key+'0');
    tree_to_string(node->left, target);
    tree_to_string(node->right, target);
    return target;
  }

    bool isSubstree(Node* t1, Node* t2){
    if(!t1){
      return false;
    }
    if(!t2){
      return false;
    }

    std::string s1;
    std::string s2;
    tree_to_string(t1, s1);
    tree_to_string(t2, s2);

    if(s1.find(s2) != std::string::npos){
      return true;
    }
    else{
      return false;
    }
  }

};

int main(){

  Tree tree;

  Node* t1 = nullptr;
  t1 = tree.insert(t1, 5);
  t1 = tree.insert(t1, 3);
  t1 = tree.insert(t1, 2);
  t1 = tree.insert(t1, 4);
  t1 = tree.insert(t1, 7);
  t1 = tree.insert(t1, 6);
  t1 = tree.insert(t1, 8);

  Node* t2 = nullptr;
  t2 = tree.insert(t2, 7);
  t2 = tree.insert(t2, 6);
  t2 = tree.insert(t2, 8);

  std::string s1;
  std::string s2;

  try{
    throw tree.isSubstree(t1, t2);
  }
  catch(bool result){
    if(result){
      std::cout << tree.tree_to_string(t2, s2) <<" is a subtree of " << tree.tree_to_string(t1, s1) << std::endl;
    }
    else{
      std::cout << tree.tree_to_string(t2, s2) <<" is NOT a subtree of " << tree.tree_to_string(t1, s1) << std::endl;
    }
  }
  return 0;
}