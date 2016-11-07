//  wrong answer, I still do not find out what is the wrong
//  can pass the sample tests

#include <iostream>
#include <string>
using namespace std;

//  valid character
bool isValid(char ch) {
  if (ch >= 'A' && ch <= 'Z') return true;
  if (ch >= 'a' && ch <= 'z') return true;
  if (ch >= '0' && ch <= '9') return true;
  if (ch == '.' || ch == '_' || ch == '-') return true;
  return false;
}

string change(string substring) {
  int n = substring.length();
  int index, pos;
  pos = substring.find("@");
  //  there are two adjacent dots
  for (int i = 0; i < n - 1; ++i) {
    if (substring[i] == '.' && substring[i + 1] == '.') {
      if (i + 1 < pos - 1) {
        for (int j = 0; j <= i + 1; j++)
          substring[j] = ' ';
      } else if (i > pos + 1) {
        for (int j = i; j < n; j++)
          substring[j] = ' ';
      } else {
        substring = "";
        break;
      }
    }
  }
  int left, right;
  if (substring == "") return substring;
  if (pos == 0 || pos == n - 1) {
    substring = "";
    return substring;
  }
  left = pos - 1;
  // find a substring from @ to its left and right until meet a invalid character
  while (isValid(substring[left])) {
    left--;
    if (left == -1) break;
  }
  right = pos + 1;
  while (isValid(substring[right])) {
    right++;
    if (right == substring.length())
    break;
  }
  substring = substring.substr(left + 1, right - left - 1);
  if (substring[0] == '.' || substring[substring.length() - 1] == '.')
    substring = "";
  return substring;
}

int main() {
  string str, substring;
  int leftIndex, rightIndex, count, pos;

  while (getline(cin, str)) {
    // no @
    if (str.find("@") == std::string::npos)
      continue;

    while (str.find("@") != std::string::npos) {
      pos = str.find("@");
      if (pos == 0 || pos == str.length()) break;
      leftIndex = pos - 1;
      while (isValid(str[leftIndex])) {
        leftIndex--;
        if (leftIndex == -1) break;
      }
      rightIndex = pos + 1;
      while (isValid(str[rightIndex])) {
        rightIndex++;
        if (rightIndex == str.length()) break;
      }
      substring = str.substr(leftIndex + 1, rightIndex - leftIndex - 1);
      substring = change(substring);
      if (substring != "") {
        cout << substring << endl;
      }
       str[pos] = ' ';
    }
  }
}
