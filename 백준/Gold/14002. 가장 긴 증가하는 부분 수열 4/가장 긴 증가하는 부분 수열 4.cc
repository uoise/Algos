#include <algorithm>
#include <iostream>
using namespace std;
int n;

void lis() {
  int v[n + 1], L[n + 1], ix[n + 1];
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    const int t = v[i];
    if (idx == 0) {
      L[idx++] = t;
      ix[i] = 0;
    } else {
      if (L[idx - 1] < t) {
        ix[i] = idx;
        L[idx++] = t;
      } else {
        ix[i] = lower_bound(L, L + idx, t) - L;
        L[lower_bound(L, L + idx, t) - L] = t;
      }
    }
  }

  cout << idx << '\n';
  int r[idx + 1], t = 0;
  for (int i = n; i > 0; i--) {
    if (idx == ix[i] + 1) {
      r[t++] = v[i];
      idx--;
    }
  }

  for (int i = t - 1; i >= 0; i--) cout << r[i] << ' ';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  lis();
}
