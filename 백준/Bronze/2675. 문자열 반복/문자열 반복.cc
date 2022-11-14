#include <iostream>
using namespace std;

void solve() {
    uint32_t R;
    string S;
    cin >> R >> S;
    for (uint32_t i = 0; i < S.length(); i++) {
        for (uint32_t j = 0; j < R; j++) {
            cout << S.at(i);
        }
    }
    cout << '\n';
}

int main() {
    uint32_t T;
    cin >> T;
    for (uint32_t i = 0; i < T; i++) {
        solve();
    }
}