#include <cstdio>
#include <vector>

constexpr int MN = 1e5 + 1;
int n, c[MN];
bool cuv(int x) { return c[x] > 1; }
bool sol(int t, int K) { return t == 1 ? cuv(K) : true; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    ++c[s], ++c[e];
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int t, K;
    scanf("%d %d", &t, &K);
    printf("%s\n", sol(t, K) ? "yes" : "no");
  }
}