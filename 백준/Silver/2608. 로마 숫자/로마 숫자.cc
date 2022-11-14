#include <iostream>

using namespace std;
char cv[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int nv[] = {1, 5, 10, 50, 100, 500, 1000};
int psr(string x) {
  int res = 0, tmp = -7;
  for (const auto& c : x) {
    int idx;
    for (int i = 0; i < 7; i++)
      if (c == cv[i]) idx = i;
    if (idx - tmp == 1)
      res += nv[tmp] * 3;
    else if (idx - tmp == 2 && !(idx % 2))
      res += nv[tmp] * 8;
    else
      res += nv[idx];
    tmp = idx;
  }
  return res;
}

void sol(string x, string y) {
  string rss = "";
  int rsi = psr(x) + psr(y), ord = 0, fiv = 0;
  cout << rsi << '\n';
  while (rsi) {
    int tmp = rsi % 10;
    if (tmp == 9) {
      rss += cv[ord + 2];
      rss += cv[ord];
    } else if (tmp == 4) {
      rss += cv[ord + 1];
      rss += cv[ord];
    } else {
      if (tmp >= 5) {
        fiv = 1;
        tmp -= 5;
      }
      while (tmp--) {
        rss += cv[ord];
      }
      if (fiv) {
        rss += cv[ord + 1];
        fiv--;
      }
    }
    rsi /= 10;
    ord += 2;
  }
  for (int i = rss.size() - 1; i >= 0; i--) cout << rss[i];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string x, y;
  cin >> x >> y;
  sol(x, y);
}