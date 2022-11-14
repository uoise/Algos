#include <iostream>
int arr[1001], dp[1001], dn[1001];

void solve(int N) {
    int res = 1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1;
        dn[i] = 1;
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            if ((arr[i] > arr[j]) && (dp[i] < (dp[j] + 1))) dp[i] = dp[j] + 1;

    for (int i = N; i >= 1; i--)
        for (int j = N; j >= i; j--)
            if ((arr[i] > arr[j]) && (dn[i] < (dn[j] + 1))) dn[i] = dn[j] + 1;

    for (int i = 1; i <= N; i++)
        if (res < (--dp[i] + --dn[i] + 1)) res = dp[i] + dn[i] + 1;

    printf("%d\n", res);
}
int main() {
    int N;
    scanf("%d", &N);
    solve(N);
}
