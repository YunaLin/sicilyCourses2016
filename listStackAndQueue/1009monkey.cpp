#include <iostream>
using namespace std;

int main() {
  int monkey[1010];
  int t, n, m, count, total, winner;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
      monkey[i] = i + 1;
    }
    for (int i = n; i < 1010; i++)
      monkey[i] = -1;
    count = total = 0;
    if (m > n) m %= n;
    for (int i = 0; i < n; i++) {
      if (monkey[i] != -1) {
        count++;
      }
      if (count == m) {
        monkey[i] = -1;
        total += 1;
        count = 0;
      }
      if (total == n - 1) break;
      if (i == n - 1) i = -1;
    }
    for (int i = 0; i < n; ++i) {
      if (monkey[i] != -1) {
        cout << monkey[i] << endl;
        break;
      }
    }
  }
  return 0;
}
