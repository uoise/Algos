#include <iostream>
using namespace std;

bool nv[10000];
int sol(const int n, const int k) {
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (!nv[i])
      for (int j = 1; i * j <= n; j++) {
        if (!nv[i * j]) {
          nv[i * j] = 1;
          if (++cnt == k) return i * j;
        }
      }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  cout << sol(n, k);
}