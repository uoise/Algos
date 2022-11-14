#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ffp = pair<float, float>;
struct iid {
  int b, e;
  float c;
  iid(int b = 0, int e = 0, float c = 0) : b(b), e(e), c(c) {}
};
bool operator<(const iid& x, const iid& y) { return x.c < y.c; }
vector<iid> ev;
vector<int> pv;
ffp vd[101];
int N;

float len(const ffp& x, const ffp& y) {
  return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

int fnd(const int x) {
  if (pv[x] == x) return x;
  return pv[x] = fnd(pv[x]);
}

float mst() {
  float r = 0;
  for (const auto& cur : ev) {
    const int bb = fnd(cur.b), ee = fnd(cur.e);
    if (bb != ee) {
      pv[bb] = ee;
      r += cur.c;
    }
  }
  return r;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%f %f", &vd[i].first, &vd[i].second);
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) ev.push_back({i, j, len(vd[i], vd[j])});
  pv.resize(ev.size());
  sort(ev.begin(), ev.end());
  for (int i = 0; i < pv.size(); i++) pv[i] = i;
  printf("%f", mst());
}
