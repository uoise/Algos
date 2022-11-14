#include <iostream>
#include <map>
using namespace std;

void solve() {
  int N, M, i;
  long long r = 1, rr = 0;
  string s1, s2;
  map<string, int> sv;
  map<string, int>::iterator it;

  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> s1 >> s2;
    if (sv.count(s2))
      sv[s2]++;
    else
      sv.insert(make_pair(s2, 1));
  }
  for (it = sv.begin(); it != sv.end(); it++) r *= (it->second + 1);
  cout << --r << '\n';
}

int main() {
  int T;
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  while (T--) solve();
}