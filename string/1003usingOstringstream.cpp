// time limit
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int main() {
  string substring, str;
  int num;
  int n;
  int length;
  substring = "";
  str = "";
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
    ostringstream ss;
    scanf("%d", &num);
    ss << num;
    substring += ss.str();
  }
  cin >> length;
  for (int i = 0; i < length; ++i) {
    ostringstream ss;
    scanf("%d", &num);
    ss << num;
    str += ss.str();
  }
  int result;
  result = str.find(substring);
  if (result != std::string::npos)
  cout << result << endl;
  else
  cout << "no solution" << endl;
  }
  return 0;
}
