#include <iostream>
#include <string>
using namespace std;
//  valid character
bool isValid(char ch) {
  if (ch >= 'A' && ch <= 'Z') return true;
  if (ch >= 'a' && ch <= 'z') return true;
  if (ch >= '0' && ch <= '9') return true;
  if (ch == '_' || ch == '-') return true;
  return false;
}
int main() {
  string str;
  int left, right;
  while (getline(cin, str)) {
    if (str.size() == 0) continue;
    for (int i = 1; i < str.size() - 1; ++i) {
      if (str[i] == '@' && isValid(str[i - 1]) && isValid(str[i + 1])) {
        left = i - 1;
        right = i + 1;
        for (left = i - 1; left >= 0; left--) {
          if (str[left] == '.' && str[left + 1] == '.') {
            break;
          }
          if (str[left] != '.' && !isValid(str[left])) {
            break;
          }
        }
        if (str[left + 1] == '.') left = left + 1;
        for (right = i + 1; right < str.size(); ++right) {
          if (str[right] == '.' && str[right - 1] == '.') {
            break;
          }
          if (str[right] != '.' && !isValid(str[right]))
            break;
        }
        if (str[right - 1] == '.') right = right - 1;
        for (int j = left + 1; j <= right - 1; ++j)
          cout << str[j];
        cout << endl;
      }
    }
  }
}
