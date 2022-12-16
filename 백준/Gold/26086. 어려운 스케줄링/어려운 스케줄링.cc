#include <algorithm>
#include <cstdio>
#include <deque>
#include <functional>

using namespace std;

int n, q, k, x, ls, lr, r;
int sol() {
  deque<pair<int, int>> vv;
  deque<int> pq, rq;
  scanf("%d %d %d", &n, &q, &k);

  for (int i = 0; i < q; i++) {
    scanf("%d", &x);
    if (!x) {
      scanf("%d", &x);
      vv.push_back({x, r});
    } else if (x & 1) {
      ls = vv.size();
      lr = r;
    } else {
      r ^= 1;
    }
  }

  if (r ^ lr)
    sort(vv.begin(), vv.begin() + ls, greater<>());
  else
    sort(vv.begin(), vv.begin() + ls);

  for (int i = ls; i < vv.size(); i++) {
    if (vv[i].second ^ r)
      rq.push_back(vv[i].first);
    else
      pq.push_front(vv[i].first);
  }

  int ps = pq.size();

  if (--k < ps)
    return pq[k];
  else if (k > ps + ls)
    return rq[k - ps - ls];
  else
    return vv[k - ps].first;
}

int main() { printf("%d", sol()); }