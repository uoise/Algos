#include <cstdio>
#include <queue>

std::queue<std::pair<int, int>> q;
int s, b, c, d, v[1001][1001];
int sol() {
  v[1][0] = 1;
  q.push({1, 0});
  while (!q.empty()) {
    c = q.front().first, b = q.front().second, d = v[c][b] + 1;
    q.pop();
    if (c == s) return d - 2;
    if (!v[c - 1][b]) {
      v[c - 1][b] = d;
      q.push({c - 1, b});
    }

    if (c + b <= s && !v[c + b][b]) {
      v[c + b][b] = d;
      q.push({c + b, b});
    }

    if (!v[c][c]) {
      v[c][c] = d;
      q.push({c, c});
    }
  }
  return 0;
}

int main() {
  scanf("%d", &s);
  printf("%d", sol());
}