#include <iostream>
#include <queue>
#include <string>

using namespace std;

constexpr int MX = 101, INF = 0x3f3f3f3f;

struct mmr {
  string ns;
  int ml, fc, ss, xc;
  bool operator<(const mmr& o) const {
    if (ml != o.ml) return ml < o.ml;
    if (fc != o.fc) return fc > o.fc;
    if (ss != o.ss) return ss > o.ss;
    if (xc != o.xc) return xc > o.xc;
    return ns > o.ns;
  }
  bool operator!=(const mmr& o) const {
    return (ml != o.ml) || (fc != o.fc) || (ss != o.ss) || (xc != o.xc);
  }
};

priority_queue<mmr> q;
string sv[7];
int w;
mmr pse() {
  mmr ret = {"", 0, 0, INF, 0};
  cin >> ret.ns;
  for (int i = 0; i < 7; i++) cin >> sv[i];
  int ml = 0, fc = 0, ss = INF, lf = 0;
  for (int i = 0; i < 7 * w; i++) {
    const auto& cur = sv[i % 7][i / 7];
    if (cur == 'O') {
      ++ml, lf = 0;
      if (ss == INF) ss = i;
    } else if (cur == 'F') {
      if (ml) ++fc, ++lf;
    } else if (cur == 'X') {
      ++ret.xc;
      if (ret.ml < ml || (ret.ml == ml && ret.fc > fc - lf)) {
        ret.ml = ml;
        ret.fc = fc - lf;
        ret.ss = ss;
      }
      ml = 0, fc = 0, ss = INF;
    }
  }
  if (ret.ml < ml || (ret.ml == ml && ret.fc > fc - lf)) {
    ret.ml = ml;
    ret.fc = fc - lf;
    ret.ss = ss;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, ord = 1;
  cin >> n >> w;
  while (n--) q.push(pse());
  while (!q.empty()) {
    const mmr t = q.top();
    q.pop();
    cout << ord << ". " << t.ns << '\n';
    if (!q.empty() && (t != q.top())) ++ord;
  }
}