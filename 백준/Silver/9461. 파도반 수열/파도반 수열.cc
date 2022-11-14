#include <iostream>
long long dp[101];
long long solve() {
    int N;
    scanf("%d", &N);
    if (N <= 3) return 1;
    if (N <= 5) return 2;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 5];
    return dp[N];
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) printf("%lld\n", solve());
}