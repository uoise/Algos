#include <iostream>
using namespace std;

void solve() {
    unsigned int a, b, c;
    cin >> a >> b >> c;
    if (b >= c) {
        cout << -1 << endl;
        return;
    }
    cout << a / (c - b) + 1 << endl;
}
int main() { solve(); }