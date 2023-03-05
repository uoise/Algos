#include <algorithm>
#include <cstdio>

struct ocw {
  int o, c, w;
  bool operator<(const ocw& a) const { return w == a.w ? c < a.c : w < a.w; }
  bool operator==(const ocw& a) const { return w == a.w && c == a.c; }
};

constexpr int MX = 2e5 + 1;
int n, rv[MX], cv[MX], wv[2001], s;
ocw vv[MX];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    vv[i].o = i;
    scanf("%d %d", &vv[i].c, &vv[i].w);
  }
  std::sort(vv, vv + n);
  for (int i = 0; i < n; i++) {
    rv[vv[i].o] = s - cv[vv[i].c] - wv[vv[i].w];
    if (i && vv[i] == vv[i - 1]) rv[vv[i].o] = rv[vv[i - 1].o];
    wv[vv[i].w] += vv[i].w;
    s += vv[i].w;
    cv[vv[i].c] += vv[i].w;
  }
  for (int i = 0; i < n; i++) printf("%d\n", rv[i]);
}