#include <cstdio>
#include <queue>

constexpr char G[] = {'A', 'C', 'G', 'T'};
std::queue<int> q;
char s[1000001];
int n, p, v[4], l[4], r;
int cti(const char& c) {
  for (int i = 0; i < 4; i++) if (c == G[i]) return i;
  return -1;
}

int main() {
  scanf("%d %d\n%s", &n, &p, s);
  for (int i = 0; i < 4; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    q.push(i);
    ++l[cti(s[i])];
    if (q.size() < p) continue;
    if (q.size() > p) {
      --l[cti(s[q.front()])];
      q.pop();
    }
    bool b = 1;
    for (int j = 0; b && j < 4; j++) b = v[j] <= l[j];
    r += b;
  }
  printf("%d", r);
}