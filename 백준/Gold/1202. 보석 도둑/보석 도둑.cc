#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

priority_queue<pair<int, int>> pq;
multiset<int> sv;
int n, k, x, y;
long long r;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    pq.push({y, -x});
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &x);
    sv.insert(x);
  }
  while (!pq.empty()) {
    const int cv = pq.top().first, cm = -pq.top().second;
    pq.pop();
    auto f = sv.lower_bound(cm);
    if (f != sv.end()) {
      r += cv;
      sv.erase(f);
    }
  }
  printf("%lld", r);
}