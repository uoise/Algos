#include <algorithm>
#include <iostream>
int dp[1000001];
int mx;
int *idx;

void solve(int N) {
    for (int i = 1; i <= N; i++) {
        int inp;
        scanf("%d", &inp);
        idx = std::lower_bound(dp + 1, dp + mx + 1, inp);
        *idx = inp;
        if (idx == dp + mx + 1) mx++;
    }
    printf("%d\n", mx);
}
int main() {
    int N;
    scanf("%d", &N);
    solve(N);
}