#include <algorithm>
#include <iostream>
int arr[1001];
int mx;
int *idx;

void solve(int N) {
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    for (int i = 1; i <= N; i++) {
        idx = std::lower_bound(arr + 1, arr + mx + 1, arr[i]);
        *idx = arr[i];
        if (idx == arr + mx + 1) mx++;
    }
    printf("%d\n", mx);
}
int main() {
    int N;
    scanf("%d", &N);
    solve(N);
}