#include <iostream>
using namespace std;
void solve() {
    unsigned int a, i = 0;
    unsigned long r = 1;
    cin >> a;
    if (a == 1) {
        cout << 1 << endl;
        return;
    }
    while (r < a) {
        r += 6 * i++;
    }
    cout << i << endl;
}
int main() { solve(); }
