#include <iostream>
#include <vector>
using namespace std;

void solve() {
    uint32_t n = 1, r = 0, m = 0;
    vector<uint32_t> inp;
    vector<uint32_t>::iterator it;

    while (n != 0) {
        cin >> n;
        if (n > m) m = n;
        inp.push_back(n);
    }

    bool *prime = new bool[2 * m + 1];
    prime[0] = false;
    prime[1] = false;
    for (uint32_t i = 2; i <= 2 * m; i++) prime[i] = true;
    for (uint32_t j = 2; j <= 2 * m; j++) {
        for (uint32_t i = 2; j * i <= 2 * m; i++) {
            prime[j * i] = false;
        }
    }
    for (it = inp.begin(); *it != 0; it++) {
        n = *it;
        r = 0;
        for (uint32_t i = n+1; i <= 2 * n; i++)
            if (prime[i]) r++;
        cout << r << '\n';
    }
}
int main() { solve(); }