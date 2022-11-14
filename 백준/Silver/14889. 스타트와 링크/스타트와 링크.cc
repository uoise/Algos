#include <iostream>
#define MXX 20
bool team[MXX];
int vv[MXX][MXX];
int N, mn = 10000000;
int abs(const int a) { return a > 0 ? a : a * -1; }

void solve(int idx = 1, int cnt = 0) {
    int i;
    if (cnt == N / 2) {
        int x = 0, y = 0;
        for (i = 1; i < N; i++)
            for (int j = 0; j < i; j++)
                if (team[i] == team[j]) {
                    if (team[i])
                        x += vv[i][j] + vv[j][i];
                    else
                        y += vv[i][j] + vv[j][i];
                }
        if (mn > abs(x - y)) mn = abs(x - y);
    }
    for (i = idx; i < N; i++)
        if (!team[i]) {
            team[i] = true;
            solve(i, cnt + 1);
            team[i] = false;
        }
}
int main() {
    int t, i, j;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) scanf("%d", &vv[i][j]);
    solve();
    printf("%d\n", mn);
}