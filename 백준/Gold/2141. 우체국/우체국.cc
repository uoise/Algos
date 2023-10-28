#include <algorithm>
#include <cstdio>

int n;
long long s, r;
std::pair<int, int> xa[100001];
int sol() {
  std::sort(xa, xa + n);
  s = ++s / 2;
  for (int i = 0; i < n; i++) {
    r += xa[i].second;
    if (r >= s) return xa[i].first;
  }
  return -1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &xa[i].first, &xa[i].second);
    s += xa[i].second;
  }

  printf("%d", sol());
}