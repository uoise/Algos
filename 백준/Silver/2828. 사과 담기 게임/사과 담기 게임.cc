#include <iostream>

using namespace std;

int n, m, j;

int sol() {
  int vv[j], cur = 1, r = 0;
  --m;
  for (auto& i : vv) cin >> i;
  for (const auto& i : vv) {
    if (i < cur) {
      r += (cur - i);
      cur = i;
    } else if (i > cur + m) {
      r += (i - cur - m);
      cur = i - m;
    }
  }
  return r;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> j;
  cout << sol();
}