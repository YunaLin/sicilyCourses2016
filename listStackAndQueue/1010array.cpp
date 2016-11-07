#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> dataOne;
  vector<int> dataSecond;
  int num;
  for (int i = 0; i < 5; ++i) {
    cin >> num;
    dataOne.push_back(num);
  }
  for (int i = 0; i < 5; ++i) {
    cin >> num;
    dataSecond.push_back(num);
  }
  int temp, tmp, i;
  while (true) {
    if (dataSecond[0] < dataOne[4]) {
      temp = dataSecond[0];
      tmp = dataOne[4];
      for (i = 3; i >= 0; i--) {
        if (dataOne[i] > temp)
          dataOne[i + 1] = dataOne[i];
        else
          break;
      }
      dataOne[i + 1] = temp;

      for (i = 1; i <= 4; ++i) {
        if (dataSecond[i] < tmp)
          dataSecond[i - 1] = dataSecond[i];
        else
          break;bi
      }
      dataSecond[i - 1] = tmp;
    } else {
      break;
    }
  }
  for (int i = 0; i < 5; ++i)
    cout << dataOne[i] << " ";
  for (int i = 0; i < 5; ++i)
    cout << dataSecond[i] << " ";
  return 0;
}
