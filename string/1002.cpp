#include <iostream>
#include <string>
using namespace std;
bool isEmpty(string str) {
  if (str.length() == 0) return true;
  int count = 0;
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == ' ')
      count++;
  }
  if (count == str.length()) return true;
  return false;
}

void change(string str) {
  string left, right;
  int n, mid;
  char temp;
  n = str.length();
  mid = (n + 1)/2;
  left = str.substr(0, mid);
  right = str.substr(mid, mid);
  n = left.length();
  for (int i = 0; i < n/2; ++i) {
    temp = left[i];
    left[i] = left[n - 1 - i];
    left[n - 1 - i] = temp;
  }
  n = right.length();
  for (int i = 0; i < n/2; ++i) {
    temp = right[i];
    right[i] = right[n - 1 - i];
    right[n - 1 - i] = temp;
  }
  str = left + right;
  if (!isEmpty(str))
  cout << str << endl;
}

int main() {
  string str1, str2;
  int count = 0;
  while (getline(cin, str1)&&getline(cin, str2)) {
    change(str2);
    change(str1);
  }
  return 0;
}
