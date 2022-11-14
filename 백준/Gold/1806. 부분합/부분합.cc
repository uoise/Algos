#include <iostream>
using namespace std;

int n, s;
int sol(int *v) {
  int r1 = 0, r2 = 1, len = 2e9;
  while (r1 <= n && r2 <= n) {
    if (v[r2] - v[r1] >= s)
      if (r2 - r1 >= len)
        r1++;
      else
        len = r2 - r1;
    else
      r2++;
  }
  return len == 2e9 ? 0 : len;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> s;
  int v[n + 1];
  v[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  cout << sol(v);
}
