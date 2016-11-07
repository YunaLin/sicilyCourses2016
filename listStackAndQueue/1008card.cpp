#include <iostream>
#include <list>
using namespace std;
int main() {
  int t, n, ele, temp;
  cin >> t;
  while (t--) {
    cin >> n;
    list<int> data;
    for (int i = 0; i < n; ++i) {
      data.push_back(i + 1);
    }
    while (data.size() >= 2) {
      cout << data.front() << " ";
      data.pop_front();
      temp = data.front();
      data.pop_front();
      data.push_back(temp);
    }
    cout << data.front() << " " << endl;
  }
  return 0;
}
