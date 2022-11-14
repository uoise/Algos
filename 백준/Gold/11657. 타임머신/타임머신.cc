#include <iostream>
#include <vector>
using namespace std;
struct bec {
  int beg, end, cst;
  bec(int b, int e, int c) : beg(b), end(e), cst(c) {}
};
const long long INF = 2e10;
int N, M;
vector<long long> dst;
vector<bec> grp;

bool b_fs() {
  dst[1] = 0;
  for (int i = 1; i < N; i++)
    for (const auto& c : grp)
      if (dst[c.beg] != INF && dst[c.beg] + c.cst < dst[c.end])
        dst[c.end] = dst[c.beg] + c.cst;

  for (const auto& c : grp)
    if (dst[c.beg] != INF && dst[c.beg] + c.cst < dst[c.end]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N >> M;

  dst.resize(N + 1, INF);
  int a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    grp.push_back({a, b, c});
  }
  if (b_fs())
    for (int i = 2; i <= N; i++) {
      if (dst[i] != INF) cout << dst[i] << '\n';
      else cout << "-1\n";
    }
  else
    cout << -1;
}

