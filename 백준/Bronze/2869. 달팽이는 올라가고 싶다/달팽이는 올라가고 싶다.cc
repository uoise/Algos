#include <cmath>
#include <iostream>
using namespace std;
void solve() {
    unsigned a, b, v;
    cin >> a >> b >> v;
    if (a == b) {
        cout << -1 << endl;
        return;
    }
    if (a == v) {
        cout << 1 << endl;
        return;
    }
    double r = (double)(v - b) / (double)(a - b);
    cout << (long)ceil(r) << endl;
}

int main() { solve(); }
