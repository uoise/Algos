#include <algorithm>
#include <iostream>
bool pmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}
std::pair<int, int> arr[101];

int* idx;
int mx, dp[101];
void solve(int N) {
    std::sort(arr + 1, arr + N + 1, pmp);
    for (int i = 1; i <= N; i++) {
        idx = std::lower_bound(dp + 1, dp + mx + 1, arr[i].second);
        *idx = arr[i].second;
        if (idx == dp + mx + 1) mx++;
    }
    printf("%d\n", N - mx);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i].first);
        scanf("%d", &arr[i].second);
    }
    solve(N);
}