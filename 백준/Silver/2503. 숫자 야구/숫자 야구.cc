#include <iostream>

using namespace std;
constexpr int MX = 1000;
bool rv[MX];

int sol(const int n) {
  int vv[n][3], sv[n], bv[n], inp, res = 0;
  for (int i = 0; i < MX; i++) {
    const int n0 = i / 100, n1 = (i / 10) % 10, n2 = i % 10;
    if (!n0 || !n1 || !n2 || (n0 == n1) || (n1 == n2) || (n2 == n0))
      rv[i] = true;
  }
  for (int i = 0; i < n; i++) {
    cin >> inp >> sv[i] >> bv[i];
    vv[i][0] = inp / 100, vv[i][1] = (inp / 10) % 10, vv[i][2] = inp % 10;
  }

  for (int cur = 0; cur < n; cur++) {
    for (register int i = 123; i < 988; i++) {
      if (!rv[i]) {
        int bc = 0, sc = 0;
        int nv[3] = {i / 100, (i / 10) % 10, i % 10};
        for (int ti = 0; ti < 3; ti++)
          for (int ni = 0; ni < 3; ni++)
            if (vv[cur][ti] == nv[ni]) (ti == ni) ? ++sc : ++bc;
        if (bc != bv[cur] || sc != sv[cur]) rv[i] = true;
      }
    }
  }

  for (const auto& i : rv)
    if (!i) ++res;
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n) << '\n';
}