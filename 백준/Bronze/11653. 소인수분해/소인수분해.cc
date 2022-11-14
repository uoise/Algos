#include <iostream>
using namespace std;

void solve() {
    uint32_t n;
    cin >> n;
    if (n == 1) return;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
            n = n / i;
            i = 1;
        }
    }
}
int main() { solve(); }