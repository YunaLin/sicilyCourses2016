#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// bool isValid(string str) {
//   int n = 0;
//   if (str.length() != 11) return false;
//   for (int i = 0; i < 11; ++i) {
//     if (str[i] == '-')
//       n++;
//     if (i == 0 && str[i] == '-')
//       return false;
//     if (i == 11 && str[i] == '-')
//       return false;
//     if (!((str[i] <= '9' && str[i] >= '0') || str[i] == '-'))
//       return false;
//
//   }
//   if (n != 2) return false;
//   for (int i = 0; i < 10; ++i)
//     if (str[i] == '-' && str[i + 1] == '-')
//       return false;
//   return true;
// }
int main() {
  string str;
  int arr[11];
  int count, sum, remain, add;
  char temp;
  while (cin >> str) {
    for (int i = 0; i <= 10; ++i)
      arr[i] = 0;
    count = 10;
    for (int i = 0; i < 12; i++) {
      if (str[i] != '-') {
        arr[count--] = str[i] - '0';
      }
    }
    sum = 0;
    for (int i = 2; i <= 10; ++i) {
      sum += arr[i]*i;
    }
    remain = sum % 11;
    add = 11 - remain;
    if (add == 10)
    cout << str << "-" << "X" << endl;
    else if (add == 11)
    cout << str << "-" << "0" << endl;
    else
    cout << str << "-" << add << endl;
  }
}
