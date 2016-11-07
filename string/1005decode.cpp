#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isNum(char ch) {
  if (ch >= '0' && ch <= '9') return true;
  else return false;
}

int main() {
  int n,num;
  string str;
  int sum, count;
  while (cin >> str && str != "XXX") {
    for (int i = 0; i < str.length(); ++i) {
      if (isNum(str[i]) && i != 0) {
        count = 1;
        int k = i;
        while (isNum(str[++k]) && i + 1 < str.length()) {
          count++;
        }
        sum = 0;
        for (int j = 0; j < count; ++j) {
          num = str[i + j] - '0';
          sum = sum + num * pow(10, count - j - 1);
        }
        sum -= 1;
        string temp = "";
        for (int j = 0; j < sum; ++j)
          temp += str[i - 1];
        str.replace(i, count, temp);
      }
    }
    cout << str << endl;
  }
  return 0;
}
