#include <iostream>
using namespace std;

void solve() {
  int N, i, t, min = 1000001, max = -1;
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> t;
    if (t > max) max = t;
    if (t < min) min = t;
  }
  cout << min * max;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}