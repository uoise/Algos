#include <iostream>
using namespace std;
uint32_t fib(uint32_t n) {
    if (n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
void solve() {
    uint32_t n;
    cin >> n;
    if (n == 0) cout << 0 << endl;
    else cout << fib(n - 1) << endl;
}

int main() { solve(); }