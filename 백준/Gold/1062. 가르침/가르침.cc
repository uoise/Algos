#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
bitset<21> alp, wv[50];
int n, k;
int nv[26] = {-1, 0,  -1, 1,  2,  3,  4,  5,  -1, 6,  7,  8,  9,
              -1, 10, 11, 12, 13, 14, -1, 15, 16, 17, 18, 19, 20};
int clc() {
  int res = n;
  for (int i = 0; i < n; i++) {
    auto neg = alp;
    neg.flip();
    neg = neg & wv[i];
    if (neg.any()) --res;
  }
  return res;
}

int btr(const int cnt, const int cur) {
  if (cnt >= k) return clc();
  if (cur > 20) return 0;

  alp[cur] = 1;
  int res = btr(cnt + 1, cur + 1);
  alp[cur] = 0;
  res = max(res, btr(cnt, cur + 1));
  return res;
}

int sol() {
  string s;
  cin >> n >> k;
  k -= 5;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (const auto& c : s)
      if (nv[c - 'a'] != -1) wv[i][nv[c - 'a']] = 1;
  }
  if (k < 0) return 0;
  return btr(0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << sol();
}
