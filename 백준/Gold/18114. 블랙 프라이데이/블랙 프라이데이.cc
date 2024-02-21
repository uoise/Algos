#include <algorithm>
#include <cstdio>

int n, k, w[5001], c;
bool sol() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    if (w[i] == k) c = 1;
  }
  if (c) return 1;
  std::sort(w, w + n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) if (w[i] + w[j] == k) return 1;
    int s = i + 1, e = n - 1, r = w[i];
    while (s < e) {
      c = r + w[s] + w[e];
      if (c == k) return 1;
      if (c < k)
        ++s;
      else
        --e;
    }
  }
  return 0;
}

int main() { printf("%d", sol()); }