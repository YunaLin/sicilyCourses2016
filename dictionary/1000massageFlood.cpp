//  注意两点,第一是大小写不敏感,第二是如果信息来自朋友,直接将那个朋友erase,而不是另外再声明一个
// 存储message的set
#include <iostream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

int main() {
  int n, m;
  string str;
  while (cin >> n && n != 0) {
      cin >> m;
      set<string> friends;
      for (int i = 0; i < n; ++i) {
        cin >> str;
        for (int j = 0; j < str.length(); ++j) {
          str[j] = tolower(str[j]);
        }
        friends.insert(str);
      }
      for (int i = 0; i < m; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); ++j)
          str[j] = tolower(str[j]);
        set<string>::iterator it = friends.find(str);
        if (it != friends.end()) {
          friends.erase(it);
        }
      }
      cout << friends.size() << endl;
  }
  return 0;
}
