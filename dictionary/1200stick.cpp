#include<iostream>
using namespace std;

int main() {
  int n;
  int sticks[100];
  while (cin >> n && n != 0) {
    for (int i = 0; i < n; ++i)
      cin >> sticks[i];
    for (int i = 0; i < n; ++i) {
      if (sticks[i] == -1) continue;
      for (int j = 0; j < n; ++j) {
        if (sticks[i] == sticks[j]&&i != j) {
          sticks[i] = -1;
          sticks[j] = -1;
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i)
      if (sticks[i] != -1)
      cout << sticks[i] << endl;
  }
  return 0;
}
// #include<iostream>
// using namespace std;
//
// int main() {
//   int n;
//   while (cin >> n&&n != 0) {
//     int temp;
//     int result = 0;
//     while (n--) {
//       cin >> temp;
//       // 两个相同的数做异或运算得0,0与任何数做异或运算是其本身
//       result ^= temp;
//     }
//     cout << result << endl;
//   }
//   return 0;
// }
