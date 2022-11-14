#include <iostream>
using namespace std;
void solve() {
    int a, n = 0, r = 1;
    cin >> a;
    if (a == 1) {
        cout << 1 << "/" << 1 << endl;
        return;
    }
    while (++n) {
        r += n;
        if (r > a) break;
    }
    a = r - a;
    r -= n;
    a = n-a;
    if(n%2 ==0)cout << 1 + a << "/" << n - a << endl;
    else cout << n - a << "/" << 1 + a << endl;
}
int main() { solve(); }
