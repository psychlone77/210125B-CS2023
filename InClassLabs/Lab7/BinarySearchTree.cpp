#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root == NULL){
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node == NULL){ //create new node
    struct node *node = new struct node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
  }
  else{
    if(key<=node->key){
      node->left = insertNode(node->left, key);
      return node;
    }
    else{
      node->right = insertNode(node->right,key);
      return node;
    }
  }
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root == NULL){
    return root;
  }
  else{
    if(key < root->key){ //go to left subtree
      root->left = deleteNode(root->left,key);
      return root;
    }
    else if (key > root->key){ //go to right subtree
      root->right = deleteNode(root->right, key);
      return root;
    }
    else{ //when key is found
      if (root->left == NULL && root->right ==NULL){ //no child exists
        delete root;
        root = NULL;
        return root;
      }
      else if (root->left == NULL){ //only right child exist
        struct node* temp = root;
        root = root->right;
        delete temp;
        return root;
      }
      else if (root->right == NULL){ //only left child exist
        struct node* temp = root;
        root = root->left;
        delete temp;
        return root;
      }
      else{ //both chidren exist
        struct node* temp = root->right;
        while (temp != NULL && temp->left != NULL){ //find minimum node inside subtree
          temp = temp->left;
        }//while loop ends
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);
        return root;
      }
    }
  }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
