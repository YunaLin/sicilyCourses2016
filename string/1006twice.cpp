#include <iostream>
#include <string>
using namespace std;

int main() {
  int t, n;
  int num;
  int data[30];
  int count, temp;
  cin >> t;
  while (t--) {
    cin >> n;
    count = 0;
    for (int i = 0; i < 30; ++i)
      data[i] = 0;
    for (int i = 0; i < n; ++i)
      cin >> data[i];
    for (int i = 0; i < n; ++i) {
      for (int j = n - 1; j > i; --j) {
        if (data[j] < data[j - 1]) {
          temp = data[j];
          data[j] = data[j - 1];
          data[j - 1] = temp;
        }
      }
    }
    // for (int i = 0; i < n; ++i)
    //   cout << data[i] << " ";
    // cout << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (data[j] == data[i] * 2) {
          count++;
          break;
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}
