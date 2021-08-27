#include <iostream>
#include <list>

struct Node{
  int key;
  int height;
  Node* left;
  Node* right;
  Node(int key){
    this->key = key;
    this->height = 0;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class AVLTree{
  private:
    int getSkew(Node* node){
      return getHeight(node->left)-getHeight(node->right);
    }
    int getMax(int a, int b){
      return (a>b)?a:b;
    }
    int getHeight(Node* node){
      if(!node){
        return 0;
      }
      else{
        return node->height;
      }
    }
    Node* leftRotate(Node* parent){
      std::cout << "Rotating left\n";
      Node* newParent = parent->right;
      Node* newParentLeft = newParent->left;

      newParent->left = parent;
      parent->right = newParentLeft;

      parent->height = 1 + getMax(getHeight(parent->left),getHeight(parent->right));
      newParent->height = 1 + getMax(getHeight(newParent->left),getHeight(newParent->right));

      return newParent;
    }
    Node* rightRotate(Node* parent){
      std::cout << "Rotating right\n";
      Node* newParent = parent->left;
      Node* newParentRight = newParent->right;

      newParent->right = parent;
      parent->left = newParentRight;

      parent->height = 1 + getMax(getHeight(parent->left),getHeight(parent->right));
      newParent->height = 1 + getMax(getHeight(newParent->left),getHeight(newParent->right));

      return newParent;
    }  
  public:
    Node* insert(Node* node, int key){
      if(!node){
        return node = new Node(key);
      }
      if(key < node->key){
        node->left = insert(node->left, key);
      }
      else if(key > node->key){
        node->right = insert(node->right, key);
      }
      else{
        return node;
      }

      node->height = 1 + getMax(getHeight(node->left),getHeight(node->right));
      int skew = getSkew(node);

      if(skew > 1 && key < node->left->key){
        return rightRotate(node);
      }
      if(skew > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
      if(skew < -1 && key > node->right->key){
        return leftRotate(node);
      }
      if(skew < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
      }
      return node;
    }
    Node* remove(Node* node, int key){
      if(!node){
        return nullptr;
      }
      if(key < node->key){
        node->left = remove(node->left, key);
      }
      else if(key > node->key){
        node->right = remove(node->right, key);
      }
      else{
        if(!node->left && !node->right){
          delete node;
          return node = nullptr;
        }
        else if(!node->left){
          Node* temp = node->right;
          delete node;
          node = temp;
        }
        else if(!node->right){
          Node* temp = node->left;
          delete node;
          node = temp;
        }
        else{
          Node* min = findMin(node->right);
          node->key = min->key;
          node->right = remove(node->right, min->key);
        }
        return node;
      }

      node->height = 1 + getMax(getHeight(node->left),getHeight(node->right));
      int skew = getSkew(node);

      if(skew > 1 && getSkew(node->left) >= 0){
        return rightRotate(node);
      }
      if(skew > 1 && getSkew(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
      if(skew < -1 && getSkew(node->right) <= 0){
        return leftRotate(node);
      }
      if(skew < -1 && getSkew(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
      }
      return node;
    }
    Node* findMin(Node* node){
      if(!node->left){
        return node;
      }
      else{
        return findMin(node->left);
      }
    }
    void print(Node* node){
      print(node->left);
      std::cout << node->key << "\t";
      print(node->right);
    }
    void printBFS(Node* node){
      std::cout << "BFS Print:\n";
      std::list<Node*> queue;
      queue.push_back(node);
      while(!queue.empty()){
        Node* front = queue.front();
        std::cout << front->key << "\t";
        queue.pop_front();
        if(front->left){
          queue.push_back(front->left);
        }
        if(front->right){
          queue.push_back(front->right);
        }
      }
      std::cout << std::endl;
    }
};


int main(){

  Node* root = nullptr;
  AVLTree t;
  root = t.insert(root, 10);
  root = t.insert(root, 5);
  root = t.insert(root, 15);
  t.printBFS(root);
  root = t.insert(root, 20);
  t.printBFS(root);
  root = t.insert(root, 25);
  t.printBFS(root);

  return 0;
}