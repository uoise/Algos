#include <cstdio>
#include <cstring>
#include <queue>

int s[2][2];
bool push(int x) {
  for (int i = 0; i < 2; i++) {
    if (s[i][0] + 1 != x) continue;
    s[i][0] = x;
    return 1;
  }

  for (int i = 0; i < 2; i++) {
    if (s[i][0] != -1) continue;
    s[i][0] = s[i][1] = x;
    return 1;
  }

  return 0;
}

bool sol() {
  int n, c = 1, r = 1;
  memset(s, -1, sizeof s);
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    if (!r) continue;
    for (int i = 0; i < 2; i++) {
      if (s[i][1] != c) continue;
      c = s[i][0] + 1;
      s[i][0] = s[i][1] = -1;
    }

    if (c == x) ++c;
    else if (!push(x)) r = 0;
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%s\n", sol() ? "YES" : "NO");
}