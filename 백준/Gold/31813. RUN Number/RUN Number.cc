#include <deque>
#include <iostream>

using namespace std;
using ll = long long;

constexpr ll NV[] = {11111111111111111LL,
                     1111111111111111LL,
                     111111111111111LL,
                     11111111111111LL,
                     1111111111111LL,
                     111111111111LL,
                     11111111111LL,
                     1111111111LL,
                     111111111LL,
                     11111111LL,
                     1111111LL,
                     111111LL,
                     11111LL,
                     1111LL,
                     111LL,
                     11LL,
                     1LL};

deque<ll> d;
bool b;
void btr(int n, ll k) {
  if (b) return;
  if (!k) {
    cout << d.size() << '\n';
    while (d.size()) {
      cout << d.front() << ' ';
      d.pop_front();
    }
    cout << '\n';
    b = 1;
    return;
  }
  if (!n) return;
  for (int i = 0; i < 17; i++) {
    for (int j = 9; j; j--) {
      if (NV[i] * j > k) continue;
      d.push_back(NV[i] * j);
      btr(n - 1, k - NV[i] * j);
      if (b) return;
      d.pop_front();
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, T;
  ll k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    b = 0;
    btr(n, k);
  }
}