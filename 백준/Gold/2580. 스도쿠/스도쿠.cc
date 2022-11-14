#include <iostream>
#include <vector>
#define NINE 9
using namespace std;
vector<pair<int, int>> vt;
int vv[9][9];
int t;
bool flag = false;
int getZ(const int& a) {
    if (a < 3) return 0;
    if (a < 6) return 3;
    return 6;
}
bool loc(const int& x, const int& y, const int& c) {
    int i, zx = getZ(x), zy = getZ(y), res = 0;
    for (i = 0; i < NINE; i++)
        if (vv[x][i] == c) return false;
    for (i = 0; i < NINE; i++)
        if (vv[i][y] == c) return false;
    for (i = 0; i < NINE; i++)
        if (vv[zx + (i / 3)][zy + (i % 3)] == c) return false;
    return true;
}

void solve(int dp) {
    int i;
    if (dp == t) {
        int j;
        for (i = 0; i < NINE; i++) {
            for (j = 0; j < NINE; j++) printf("%d ", vv[i][j]);
            printf("\n");
        }
        flag = true;
        return;
    }

    int x = vt[dp].first, y = vt[dp].second;
    for (i = 1; i <= NINE; i++) {
        if (loc(x, y, i)) {
            vv[x][y] = i;
            solve(dp + 1);
            vv[x][y] = 0;
        }
        if (flag) return;
    }
}

int main() {
    int i, j, k;
    pair<int, int> kk;
    for (i = 0; i < NINE; i++)
        for (j = 0; j < NINE; j++) {
            scanf("%d", &k);
            if (k == 0) {
                kk.first = i;
                kk.second = j;
                vt.push_back(kk);
            } else
                vv[i][j] = k;
        }
    t = vt.size();
    solve(0);
}