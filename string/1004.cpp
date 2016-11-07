#include <iostream>
#include <string>
#include <vector>
using namespace std;
//  notice that the match dnas must be empty after used
string change(string str) {
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == 'A')
      str[i] = 'T';
    else if (str[i] == 'T')
      str[i] = 'A';
    else if (str[i] == 'C')
      str[i] = 'G';
    else
      str[i] = 'C';
  }
  return str;
}

int main() {
  int t;
  cin >> t;
  int n;
  string str;
  while (t--) {
    cin >> n;
    vector<string> dna;
    for (int i = 0; i < n; ++i) {
      cin >> str;
      dna.push_back(str);
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
      str = change(dna[i]);
      for (int j = i + 1; j < n; ++j) {
        if (str == dna[j] && str != "") {
          count++;
          dna[j] = "";
          break;
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}
