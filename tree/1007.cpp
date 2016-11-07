#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Node {
  char val;
  int weight;
  Node* left;
  Node* right;
  string code;
  Node(int num, int index) {
    weight = num;
    val = 'A' + index;
    code = "";
    left = NULL;
    right = NULL;
  }
};
bool cmp(Node* one, Node* another) {
  return one->weight > another->weight;
}

void dfs(Node* root) {
  if (root->left != NULL) {
    root->left->code = root->code + "0";
    dfs(root->left);
  }
  if (root->right != NULL) {
    root->right->code = root->code + "1";
    dfs(root->right);
  }
}
int main() {
  Node *nodes[27];
  int n;
  cin >> n;
  int w[27];
  for (int i = 0; i < 27; ++i) w[i] = 0;
  char ch;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> ch;
    if (w[ch - 'A'] == 0)
      count++;
    w[ch - 'A']++;
  }
  int index = 0;
  for (int i = 0; i < 27; ++i) {
    if (w[i] > 0) {
      nodes[index++] = new Node(w[i], i);
    }
  }
  stack<Node*> myStack;
  while (count != 1) {
    sort(nodes, nodes + count, cmp);
    if (nodes[count - 1]->left == NULL && nodes[count - 1]->right == NULL) {
      myStack.push(nodes[count - 1]);
    }
    if (nodes[count - 2]->left == NULL && nodes[count - 2]->right == NULL) {
      myStack.push(nodes[count - 2]);
    }
    Node* temp = new Node(nodes[count - 1]->weight + nodes[count - 2]->weight, 0);
    temp->left = nodes[count -1];
    temp->right = nodes[count - 2];
    nodes[count - 2] = temp;
    count--;
  }
  dfs(nodes[0]);
  while (!myStack.empty()) {
    cout << myStack.top()->val << " " << myStack.top()->weight
    << " " << myStack.top()->code << endl;
    myStack.pop();
  }
  return 0;
}
