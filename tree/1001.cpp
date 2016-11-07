// attention: pow return a float number
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  string pre, pos;
  cin >> pre;
  cin >> pos;
  int len = pre.length();
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = len - 1; j > 0; --j) {
      if (pre[i] == pos[j] && pre[i + 1] == pos[j - 1]) {
        count++;
        break;
      }
    }
  }
  cout << (int)pow(2, count);
  return 0;
}
