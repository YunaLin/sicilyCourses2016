//  time limit
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  int n;
  long long temp;
  int count;
  while (cin >> n) {
    map<long long, int> number;
    for (int i = 0; i < n; ++i) {
      cin >> temp;
      map<long long, int>::iterator it = number.find(temp);
      if (it != number.end()) {
        it->second++;
      } else {
        number.insert(make_pair(temp, 1));
      }
    }
    for (auto it = number.begin(); it != number.end(); ++it) {
      cout << it->first << " " << it->second << endl;
    }
  }
  return 0;
}
