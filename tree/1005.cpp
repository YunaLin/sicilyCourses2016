#include <iostream>
#include <vector>
using namespace std;
int childs[1001], nodes[1001];

struct Node {
  char ele;
  int left;
  int right;
};
Node myTree[1001];
void preOrder(int rootId) {
  if (rootId != 0) {
    cout << myTree[rootId].ele;
    preOrder(myTree[rootId].left);
    preOrder(myTree[rootId].right);
  }
}
int main() {
  int n;
  int val, id, rootId;
  while (cin >> n) {
    for (int i = 0; i < 1001; ++i) {
      childs[i] = 0;
      nodes[i] = 0;
    }
    Node root;
    for (int i = 0; i < n; ++i) {
      cin >> id >> root.ele >> root.left >> root.right;
      myTree[id] = root;
      nodes[id] = 1;
      childs[root.left] = 1;
      childs[root.right] = 1;
    }
    int i = 0;
    for (i = 1; i < 1001; ++i) {
      if (nodes[i] != 0 && childs[i] == 0) {
        break;
      }
    }
    preOrder(i);
    cout << endl;
  }
  return 0;
}
