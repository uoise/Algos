#include <cstdio>
int n, x, r; int main() { scanf("%d", &n); for (int i = 1; i <= n; i++) { scanf("%d", &x); if ((x & 1) != (i & 1)) r = 1; } printf("%s", r ? "NO" : "YES"); }