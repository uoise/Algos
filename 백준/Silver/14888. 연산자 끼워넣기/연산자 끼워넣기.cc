#include <iostream>

int ops[4];
long vv[12];
int N;
long cur, mn = 1000000001, mx = -1000000001;

void solve(int dp) {
    if (dp == N) {
        if (mn > cur) mn = cur;
        if (mx < cur) mx = cur;
        return;
    }
    if (ops[0] > 0) {
        cur += vv[dp];
        --ops[0];
        solve(dp + 1);
        ++ops[0];
        cur -= vv[dp];
    }
    if (ops[1] > 0) {
        cur -= vv[dp];
        --ops[1];
        solve(dp + 1);
        ++ops[1];
        cur += vv[dp];
    }
    if (ops[2] > 0) {
        long mul = cur;
        cur *= vv[dp];
        --ops[2];
        solve(dp + 1);
        ++ops[2];
        cur = mul;
    }
    if (ops[3] > 0) {
        long dbb = cur;
        cur /= vv[dp];
        --ops[3];
        solve(dp + 1);
        ++ops[3];
        cur = dbb;
    }
}
int main() {
    int t, i = 0;
    scanf("%d", &N);
    while (i < N) {
        scanf("%d", &t);
        vv[i++] = t;
    }
    i = 0;
    while (i < 4) scanf("%d", &ops[i++]);
    cur = vv[0];
    solve(1);
    printf("%ld\n%ld\n", mx, mn);
}