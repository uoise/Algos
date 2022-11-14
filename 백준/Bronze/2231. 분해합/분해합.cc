#include <iostream>
using namespace std;
void solve() {
    uint32_t n;
    cin >> n;

    uint32_t r, t, i = 1;
    while (i++ <= n) {
        r = 0;
        t = i;
        while (t >= 10) {
            r += t % 10;
            t = t / 10;
        }
        r += t + i;
        if (r == n) {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main() { solve(); }