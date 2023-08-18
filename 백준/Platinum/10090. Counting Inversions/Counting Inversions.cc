#include <cstdio>

constexpr int MX = 1e6 + 1;

long long r;
int n, v[MX], t[MX];
void merge(const int& s, const int& e) {
  const int m = (s + e) / 2;
  int i = s, j = m + 1, k = s, cnt = 0;
  while (i <= m && j <= e) {
    if (v[i] <= v[j]) {
      t[k++] = v[i++];
      r += cnt;
    } else {
      t[k++] = v[j++];
      ++cnt;
    }
  }

  if (i > m) {
    while (j <= e) {
      t[k++] = v[j++];
      ++cnt;
    }
  } else {
    while (i <= m) {
      t[k++] = v[i++];
      r += cnt;
    }
  }

  for (i = s; i <= e; i++) v[i] = t[i];
}

void sol(const int& s, const int& e) {
  if (s >= e) return;
  const int m = (s + e) / 2;
  sol(s, m);
  sol(m + 1, e);
  merge(s, e);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sol(0, n - 1);
  printf("%lld", r);
}