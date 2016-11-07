//  create the tree as a right-heavy tree
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int v = 0, Node* l = NULL, Node* r = NULL):val(v),left(l),right(r) {}
};
Node* createTree(vector<int> data) {
  int n = data.size();
  int flag = 0;
  Node* cur = NULL;
  Node* root = new Node(data[0], NULL, NULL);
  for (int i = 1; i < n; ++i) {
    Node* temp = root;
    while (temp != NULL) {
      if (data[i] < temp->val) {
        flag = -1;
        cur = temp;
        temp = temp->left;
      } else {
        flag = 1;
        cur = temp;
        temp = temp->right;
      }
    }
    if (flag == -1) {
      cur->left = new Node(data[i], NULL, NULL);
    }
    if (flag == 1) {
      cur->right = new Node(data[i], NULL, NULL);
    }
  }
  return root;
}
void clearTree(Node* root) {
  if (root != NULL) {
    clearTree(root->left);
    clearTree(root->right);
    delete root;
  }
}
void preOrder(Node* root) {
  if (root != NULL) {
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}
void inOrder(Node* root) {
  if (root != NULL) {
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
  }
}
int main() {
  int n;
  int ele;
  while (cin >> n && n) {
    vector<int> datas;
    for (int i = 0; i < n; ++i) {
      cin >> ele;
      datas.push_back(ele);
    }
    Node* root = createTree(datas);
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    clearTree(root);
  }
  return 0;
}
