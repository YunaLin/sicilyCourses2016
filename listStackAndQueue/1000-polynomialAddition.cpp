// 多项式相加
// 15331207
#include <iostream>
using namespace std;

const int MAX = 10000;

int main() {
    int arr[MAX];
    for (int i = 0; i < MAX; ++i) arr[i] = 0;
    int t, n, m;
    int co, exp, max = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> co >> exp;
            if (exp > max) max = exp;
            arr[exp] = co;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> co >> exp;
            if (exp > max) max = exp;
            arr[exp] += co;
        }
        int count = 0;
        for (int i = max; i >= 0; --i)
            if (arr[i] != 0)
                count++;
        cout << count << endl;
        for (int i = max; i >= 0; --i)
            if (arr[i] != 0)
                cout << arr[i] << " " << i << endl;
        for (int i = 0; i < max + 1; i++) arr[i] = 0;
        max = 0;
    }
    return 0;
}
