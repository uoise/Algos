#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
unordered_set<string> m;
queue<pair<string, int>> q;
string s = "123456789";
bool vld() {
  for (int i = 0; i < 9; i++)
    if (s[i] != (i + 1) % 9 + '0') return 0;
  return 1;
}

int mov(const string& c, const int& w) {
  int y, x, ny, nx;
  for (int i = 0; i < 9; i++)
    if (c[i] == '0') y = i / 3, x = i % 3;

  for (int d = 0; d < 4; d++) {
    ny = y + yy[d], nx = x + xx[d];
    if (ny < 0 || ny > 2 || nx < 0 || nx > 2) continue;
    s = c;
    swap(s[y * 3 + x], s[ny * 3 + nx]);
    if (vld()) return w + 1;
    if (m.find(s) != m.end()) continue;
    m.insert(s);
    q.push({s, w + 1});
  }
  return 0;
}

int sol() {
  int r;
  for (int i = 0; i < 9; i++) {
    scanf("%d", &r);
    s[i] = '0' + r;
  }
  if (vld()) return 0;
  m.insert(s);
  q.push({s, 0});
  while (!q.empty()) {
    if (r = mov(q.front().first, q.front().second)) return r;
    q.pop();
  }
  return -1;
}

int main() { printf("%d", sol()); }