#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int v[30], n, c;
void cmb(int beg, int end, ll sum, vector<ll>& s) {
  if (sum > c) return;
  if (beg > end) return s.push_back(sum);
  cmb(beg + 1, end, sum, s);
  cmb(beg + 1, end, sum + v[beg], s);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> c;
  vector<ll> s1, s2;
  for (int i = 0; i < n; i++) cin >> v[i];

  cmb(0, n / 2 - 1, 0, s1);
  cmb(n / 2, n - 1, 0, s2);
  sort(s2.begin(), s2.end());

  ll res = 0;
  for (const ll& i : s1)
    res += upper_bound(s2.begin(), s2.end(), c - i) - s2.begin();

  cout << res;
}