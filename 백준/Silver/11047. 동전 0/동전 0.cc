#include <iostream>
int N, K, R, C[11];
void solve() {
    while (K > 0) {
        if (C[N] <= K) {
            int t = K / C[N];
            K -= (t * C[N]);
            R += t;
        }
        N--;
    }
}
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &C[i]);
    solve();
    printf("%d\n", R);
}
