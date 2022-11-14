#include <iostream>
using namespace std;
bool drec(const int a, const int b) {
  // 4 -> 2 -> 3 -> 1
  if (a == 4) return b == 2;
  if (a == 2) return b == 3;
  if (a == 3) return b == 1;
  if (a == 1) return b == 4;
}
void solve() {
  const int siz = 6;
  int K, v[siz], d[siz], i = siz, m, s, t;
  cin >> K;
  for (i = 0; i < siz; i++) cin >> d[i] >> v[i];
  m = 0;
  for (i = 1; i < siz; i++)
    if (v[m] < v[i]) m = i;

  if (v[(m + 1) % siz] > (v[(m + 5) % siz]))
    s = (m + 1) % siz;
  else
    s = (m + 5) % siz;
  if (drec(d[m], d[s]))
    i = (v[m] * v[s]) - (v[(s + 2) % siz] * v[(s + 3) % siz]);
  else
    i = (v[m] * v[s]) - (v[(m + 2) % siz] * v[(m + 3) % siz]);
  cout << i * K << '\n';
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}