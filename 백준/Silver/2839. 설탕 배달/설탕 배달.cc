#include <iostream>
using namespace std;

void solve() {
    unsigned int n, max, cur;
    unsigned int r = 0;
    bool flag = false;
    cin >> n;
    r = n / 3 + 1;
    max = r;
    cur = r + 1;
    for (int i = 0; i < max; i++) {
        if (i * 5 <= n && (n - 5 * i) % 3 == 0) cur = i + (n - 5 * i) / 3;
        if (r >= cur) {
            r = cur;
            flag = true;
        }
    }
    if (flag)
        cout << r << endl;
    else
        cout << -1 << endl;
}

int main() { solve(); }