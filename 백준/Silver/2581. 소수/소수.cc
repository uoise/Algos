#include <iostream>
using namespace std;

void solve() {
    uint32_t r = 0;
    uint32_t n, m, o;
    bool flag;
    bool min = false;
    cin >> n;
    cin >> m;
    for (int t = n; t <= m; t++) {
        flag = true;
        for (int i = 2; i <= t / 2; i++)
            if (t % i == 0) {
                flag = false;
            }
        if (t == 1 || t == 0) flag = false;
        if (!min && flag) {
            o = t;
            min = true;
        }
        if (flag) r += t;
    }

    if (r > 0)
        cout << r << endl;
    else
        cout << -1 << endl;
    if (min) cout << o << endl;
}
int main() { solve(); }