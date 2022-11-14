#include <iostream>
int dp[100001];
int solve() {
    int n, t, max = -1001;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &dp[i]);
    for (int i = 0; i < n; i++)
        if (dp[i - 1] > 0) dp[i] += dp[i - 1];
    for (int i = 0; i < n; i++)
        if (max < dp[i]) max = dp[i];
    return max;
}

int main() { printf("%d\n", solve()); }