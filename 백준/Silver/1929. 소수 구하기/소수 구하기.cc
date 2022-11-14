#include <iostream>
using namespace std;

void solve() {
    uint32_t n, m;
    cin >> n;
    cin >> m;
    bool *prime = new bool[m + 1];
    prime[0] = false;
    prime[1] = false;
    for (uint32_t i = 2; i <= m; i++) prime[i] = true;
    for (uint32_t j = 2; j <= m; j++) {
        for (uint32_t i = 2; j * i <= m; i++) {
            prime[j * i] = false;
        }
    }
    for (uint32_t i = n; i <= m; i++)
        if (prime[i]) cout << i << '\n';
}
int main() { solve(); }