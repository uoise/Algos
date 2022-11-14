#include <iostream>
using namespace std;
void solve(int N, int src = 1, int dst = 3) {
    if (N <= 1) {
        cout << src << " " << dst << '\n';
        return;
    } else {
        int tmp = 6 - src - dst;
        solve(N - 1, src, tmp);
        cout << src << " " << dst << '\n';
        solve(N - 1, tmp, dst);
    }
}

int main() {
    int N, r = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        r *= 2;
    }

    cout << --r << '\n';
    solve(N);
}