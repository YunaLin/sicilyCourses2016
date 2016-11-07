// 中序遍历!!不是前序遍历
#include <iostream>
#include <stack>
using namespace std;
template<typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T& x)) {
  if (root != NULL) {
    inorder_recursive(root->left, *visit);
    visit(root->elem);
    inorder_recursive(root->right, *visit);
  }
}
template<typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)) {
  stack<BinaryNode<T>*> myStack;
  while (!myStack.empty()||root) {
    while (root) {
      myStack.push(root);
      root = root->left;
    }
    if (!myStack.empty()) {
      root = myStack.top();
      myStack.pop();
      visit(root->elem);
      root = root->right;
    }
  }
}
