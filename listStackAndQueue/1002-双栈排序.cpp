// 运用到二分图染色等离散数学的知识
#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int seq[1001];
int edge[1001][1001];
int col[1001];
int m_min[1001];
string result;
stack<int> s1;
stack<int> s2;

bool dfs(int cur);

int main() {
  int t_num;
  while (cin >> n && n) {
    memset(seq, 0, sizeof(seq));
    memset(edge, 0, sizeof(edge));
    memset(col, 0, sizeof(col));
    memset(m_min, 0, sizeof(m_min));
    for (int i = 0; i < n; ++i)
      cin >> seq[i];
    m_min[n] = seq[n - 1];
    // 当前栈中的元素后面还有比它小的元素,这种情况不能够放在同一个栈中
    // 此处当出现这种情况的时候,二维数组edge中对应的两个元素的值为1,表示两者之间有边
    // 后面染色的时候就不能染相同的颜色.
    for (int i = n - 1; i >= 0; i--)
      m_min[i] = m_min[i + 1] < seq[i] ? m_min[i + 1]:seq[i];
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (m_min[j + 1] < seq[i] && seq[i] < seq[j])
          edge[i][j] = edge[j][i] = 1;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
    //  第一个进栈的元素先染第一种颜色,也就是col[i] = 1;
      if (col[i] == 0) {
        col[i] = 1;
        if (!dfs(i)) {
          flag = false;
          break;
        }
      }
    }
    if (!flag) {
      cout << "0" << endl;
      continue;
    }
    int t_top = 0;
    result = "";
    for (int i = 0; i < n; ++i) {
      if (col[i] == 1) {
        result += "a ";
        s1.push(seq[i]);
      } else {
        result += "c ";
        s2.push(seq[i]);
      }
      while ((!s1.empty()&&s1.top()==t_top+1)||(!s2.empty()&&s2.top()==t_top+1)) {
        if (!s1.empty()&&s1.top()==t_top + 1) {
          result += "b ";
          s1.pop();
        } else {
          result += "d ";
          s2.pop();
        }
        t_top++;
      }
    }
    result.erase(result.size() - 1, 1);
    cout << result << endl;
  }
  return 0;
}
bool dfs(int cur) {
  for (int i = 0; i < n; ++i) {
    //  两者之间右边的情况不能染同种颜色
    if (edge[cur][i]) {
      //  如果两者右边,另一种未染色,则让它们染不同的颜色
      if (col[i] == 0) {
        col[i] = 3 - col[cur];
        if (!dfs(i)) return false;
      } else if (col[i] == col[cur]) {
        //  如果两者有边,又染了同种颜色,则这种情况是错误的
        return false;
      }
    }
  }
  return true;
}
