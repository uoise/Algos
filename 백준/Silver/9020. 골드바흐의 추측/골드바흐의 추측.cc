#include <iostream>
using namespace std;

void solve() {
    uint32_t n = 1, m = 0, T;

    cin >> T;
    uint32_t inp[T];
    for (uint32_t i = 0; i < T; i++) {
        cin >> n;
        if (n > m) m = n;
        inp[i] = n;
    }

    bool *prime = new bool[m + 1];
    prime[0] = false;
    prime[1] = false;
    for (uint32_t i = 2; i <= m; i++) prime[i] = true;
    for (uint32_t j = 2; j <= m; j++) {
        for (uint32_t i = 2; j * i <= m; i++) {
            prime[j * i] = false;
        }
    }

    for (uint32_t t = 0; t < T; t++) {
        n = inp[t];
        for (n % 4 == 0 ? m = n / 2 - 1 : m = n / 2; m > 2; m -= 2) {
            if (prime[m] && prime[n - m]) break;
        }
        if (m == 1)
            cout << 2 << " " << n - 2 << '\n';
        else
            cout << m << " " << n - m << '\n';
    }
}
int main() { solve(); }