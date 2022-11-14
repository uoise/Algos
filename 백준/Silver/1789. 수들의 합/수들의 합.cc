#include <iostream>

using namespace std;
long long n, cnt, res;

void grd(long long cur) {
  if (n >= cur) {
    n -= cur;
    cnt++;
    res = max(res, cnt);
    grd(cur + 1);
    n += cur;
    cnt--;
  } else
    cur++;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  grd(0);
  cout << --res;
}