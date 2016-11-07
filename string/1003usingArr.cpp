// time limit, It was caused by for recursion
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
  int n, m;
  while (cin >> n) {
    int code[60010] = {0};
    int gate[60010] = {0};
    for (int i = 0; i < n; ++i)
      scanf("%d", &code[i]);
    cin >> m;
    for (int i = 0; i < m; ++i)
      scanf("%d", &gate[i]);
    int count = 0;
    int index = 0;
    int temp = 0;
    for (int i = 0; i < m; ++i) {
      if (code[index] == gate[i]) {
        count++;
        if (index == 0)
          temp = i;
        index++;
      } else if (count != 0 && code[index] != gate[i]) {
        count = 0;
        index = 0;
      }
      if (count == n) {
        cout << temp << endl;
        break;
      }
    }
    if (count != n)
      cout << "no solution" << endl;
  }
  return 0;
}
