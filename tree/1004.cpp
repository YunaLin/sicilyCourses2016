// pass
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main() {
  int t, x, y;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &x, &y);
    while (x != y) {
      if (x > y) x >>= 1;
      if (y > x) y >>= 1;
    }
    printf("%d\n", x);
  }
  return 0;
}
