#include <iostream>
using namespace std;
int gcd(int res, int inp) {
  while (inp != 0) {
    int t = res % inp;
    res = inp;
    inp = t;
  }
  return res;
}

void solve() {
  int N, t, i;
  cin >> N;
  int arr[N];

  for (i = 0; i < N; i++) cin >> arr[i];
  for (i = 1; i < N; i++) {
    t = arr[0] * arr[i] / gcd(arr[0], arr[i]);
    cout << t / arr[i] << "/" << t / arr[0] << '\n';
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}