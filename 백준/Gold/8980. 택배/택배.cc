#include <algorithm>
#include <cstdio>
#include <queue>

struct cse {
  int c, s, e;
  bool operator<(const cse& o) const {
    return (e - s) == (o.e - o.s) ? c < o.c : (e - s) > (o.e - o.s);
  }
};

std::priority_queue<cse> pq;
int n, c, m, s, e, w, r, v[2001];
int main() {
  scanf("%d %d %d", &n, &c, &m);
  while (m--) {
    scanf("%d %d %d", &s, &e, &w);
    pq.push({w, s, e});
  }
  
  while (!pq.empty()) {
    s = pq.top().s, e = pq.top().e, w = pq.top().c;
    pq.pop();
    m = 0;
    for (int i = s; i < e; i++) m = std::max(m, v[i]);
    w = std::min(w, c - m);
    r += w;
    for (int i = s; i < e; i++) v[i] += w;
  }

  printf("%d", r);
}