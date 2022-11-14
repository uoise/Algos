#include <iostream>

using namespace std;

int n;
int sol() {
  float fv[n];
  int r = 0, c = 0;
  for (auto& i : fv) cin >> i;
  for (const auto& i : fv) {
    if (!c && i > .0) {
      if (int(i + .5) - int(i)) ++r;
      c = 1;
    }
    r += (int)i;
  }
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}