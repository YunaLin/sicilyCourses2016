// 用vector实现
// 注意善用node使得数组能够存储多个信息,这些信息其实包含在node中
#include<iostream>
#include<vector>
using namespace std;

struct node {
  int index;
  int priority;
  node(int i = 0, int p = 0):index(i), priority(p) {};
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<node> que;
    int n, mNum;
    cin >> n >> mNum;
    int priority;
    for (int i = 0; i < n; ++i) {
      cin >> priority;
      que.push_back(node(i, priority));
    }
    int sum = 0;
    while (!que.empty()) {
      node  front_node = que.front();
      bool flag = false;
      for (int i = 1; i < que.size(); ++i) {
        if (que[i].priority > front_node.priority) {
          que.push_back(front_node);
          flag = true;
          break;
        }
      }
      que.erase(que.begin());
      if (flag == false) sum++;
      if (flag == false && front_node.index == mNum) break;
    }
    cout << sum << endl;
  }
  return 0;
}
