#include <cstdio>
#include <vector>

constexpr int MX = 2e5 + 1;

std::vector<int> vv[MX];
bool iv[MX], bv[MX];
int n;
long long r, s;
void dfs(int c) {
  for (const int& n : vv[c]) {
    if (iv[n]) ++s;
    if (!iv[n] && !bv[n]) {
      bv[n] = 1;
      dfs(n);
    }
  }
}

int main() {
  int a, b;
  char inp[MX];
  scanf("%d\n%s\n", &n, inp);
  for (int i = 0; i < n; i++) iv[i + 1] = inp[i] == '1';
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    r += (iv[a] && iv[b]) ? 2 : 0;
    vv[a].push_back(b);
    vv[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (iv[i] || bv[i]) continue;
    bv[i] = 1, s = 0;
    dfs(i);
    r += s * (s - 1);
  }

  printf("%lld", r);
}