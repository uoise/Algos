#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, r;
vector<int> p;
void prm() {
  bool* v = new bool[n + 1];
  for (int i = 2; i <= n; i++) v[i] = true;
  for (int i = 2; i * i <= n; i++)
    if (v[i])
      for (int j = i * i; j <= n; j += i) v[j] = false;
  p.push_back(0);
  for (int i = 2; i <= n; i++)
    if (v[i]) p.push_back(i);
  delete[] v;
  sort(p.begin(), p.end());
}
void sol() {
  const int sz = p.size();
  for (int i = 1; i < sz; i++) p[i] += p[i - 1];
  int r1 = 0, r2 = 1;
  while (r1 < sz && r2 < sz) {
    if (p[r2] - p[r1] == n) {
      r++;
      r2++;
    } else if (p[r2] - p[r1] > n)
      r1++;
    else
      r2++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  prm();
  sol();
  cout << r;
}
