#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
struct BinaryNode {
  T elem;
  BinaryNode* left;
  BinaryNode* right;
  BinaryNode(T d = 0, BinaryNode* l = NULL, BinaryNode* r = NULL):elem(d), left(l), right(r) {}
};
template<typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)) {
  queue<BinaryNode<T>*> myQueue;
  if (root == NULL) return;
  myQueue.push(root);
  while (!myQueue.empty()) {
    BinaryNode<T> *temp = myQueue.front();
    myQueue.pop();
    visit(temp->elem);
    if (temp->left != NULL) {
      myQueue.push(temp->left);
    }
    if (temp->right != NULL) {
      myQueue.push(temp->right);
    }
  }
}
// template<typename T>
// void visit(T & x) {
//   cout << x << " ";
// }
// template<typename T>
// BinaryNode* createTree(vector<T>& data) {
//   int n = data.size();
//   queue<BinaryNode*> myQueue;
//   int index = 0;
//   if (n == 0 || data[index] == -1) {
//     root = NULL;
//   } else {
//     root = new BinaryNode(data[index]);
//     myQueue.push(root);
//     index++;
//     while (index < n && !myQueue.empty()) {
//       BinaryNode* temp = myQueue.front();
//       myQueue.pop();
//       if (data[index] != -1) {
//         temp->left = new BinaryNode(data[index]);
//         myQueue.push(temp->left);
//       }
//       index++;
//       if (index >= n) break;
//       if (data[index] != -1) {
//         temp->right = new BinaryNode(data[index]);
//         myQueue.push(temp->right);
//       }
//       index++;
//       if (index >= n) break;
//     }
//     return root;
//   }
// }
// int main() {
//   int n, ele;
//   cout << "Please enter the number of data: ";
//   while (cin >> n && n) {
//     // the data to create the tree
//     vector<int> data;
//     for (int i = 0; i < n; ++i) {
//       cin >> ele;
//       data.push_back(ele);
//     }
//     BinaryNode<int> *root = NULL;
//     root = createTree<int>(data);
//     levelTravelsal<int>(root, *visit<int>);
//   }
//   return 0;
// }
