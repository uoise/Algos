#include <cstring>
#include <iostream>

using namespace std;

int a[100001], v[1 << 21];
int init(int n, int b, int e) {
  return v[n] = (b == e) ? a[b]
                         : init(n * 2, b, (b + e) / 2)
                         * init(n * 2 + 1, (b + e) / 2 + 1, e);
}

int mod(int n, int b, int e, int i, int x) {
  if (i < b || i > e) return v[n];
  return v[n] = (b == e) ? x
                         : mod(n * 2, b, (b + e) / 2, i, x)
                         * mod(n * 2 + 1, (b + e) / 2 + 1, e, i, x);
}

int qry(int n, int b, int e, int l, int r) {
  if (l > e || r < b) return 1;
  return (l <= b && r >= e) ? v[n]
                            : qry(n * 2, b, (b + e) / 2, l, r)
                            * qry(n * 2 + 1, (b + e) / 2 + 1, e, l, r);
}

void sol(int n, int k) {
  char o;
  int s, e;
  for (int i = 1; i <= n; i++) {
    cin >> e;
    a[i] = e ? (e > 0 ? 1 : -1) : 0;
  }
  init(1, 1, n);
  while (k--) {
    cin >> o >> s >> e;
    if (o == 'C') {
      e = e ? (e > 0 ? 1 : -1) : 0;
      if (a[s] == e) continue;
      a[s] = e;
      mod(1, 1, n, s, e);
    } else if (o == 'P') {
      e = qry(1, 1, n, s, e);
      o = e ? (e > 0 ? '+' : '-') : '0';
      cout << o;
    }
  }
  cout << '\n';
  memset(a, 0, sizeof a);
  memset(v, 0, sizeof v);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  while (cin >> n >> k) sol(n, k);
}