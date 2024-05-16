#include <cstdio>
#include <cstring>
#include <queue>

std::queue<int> q;
int v[512], m[] = {7, 56, 73, 84, 146, 273, 292, 448};
int sol() {
  int c = 0;
  for (int i = 0; i < 9; i++) {
    char s;
    scanf("%c ", &s);
    c <<= 1;
    c |= s == 'H';
  }

  while (q.size()) q.pop();
  memset(v, 0, sizeof v);
  q.push(c);
  v[c] = 1;
  while (q.size()) {
    c = q.front();
    q.pop();
    if (!c || c == (1 << 9) - 1) return v[c] - 1;
    for (int i = 0; i < 8; i++) {
      int a = c ^ m[i];
      if (v[a]) continue;
      v[a] = v[c] + 1;
      q.push(a);
    }
  }
  return -1;
}

int main() {
  int T;
  scanf("%d\n", &T);
  for (int i = 0; i < T; i++) printf("%d\n", sol());
}