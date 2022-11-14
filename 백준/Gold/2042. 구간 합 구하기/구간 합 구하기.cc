#include <cmath>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;
// https://book.acmicpc.net/ds/segment-tree
int N, M, K, H;

void init(vector<LL>& tgt, vector<LL>& tri, int nod, int beg, int end) {
  if (beg == end) {
    tri[nod] = tgt[beg];
  } else {
    init(tgt, tri, nod * 2, beg, (beg + end) / 2);
    init(tgt, tri, nod * 2 + 1, (beg + end) / 2 + 1, end);
    tri[nod] = tri[nod * 2] + tri[nod * 2 + 1];
  }
}

void update(vector<LL>& tgt, vector<LL>& tri, int nod, int beg, int end,
            int idx, LL val) {
  if (idx < beg || idx > end) return;
  if (beg == end) {
    tgt[idx] = val;
    tri[nod] = val;
    return;
  }
  update(tgt, tri, nod * 2, beg, (beg + end) / 2, idx, val);
  update(tgt, tri, nod * 2 + 1, (beg + end) / 2 + 1, end, idx, val);
  tri[nod] = tri[nod * 2] + tri[nod * 2 + 1];
}

LL query(vector<LL>& tri, int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return 0;
  if (lft <= beg && rht >= end) return tri[nod];
  LL lres = query(tri, nod * 2, beg, (beg + end) / 2, lft, rht);
  LL rres = query(tri, nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht);
  return lres + rres;
}

void solve() {
  scanf("%d %d %d", &N, &M, &K);
  vector<LL> V(N);
  for (int i = 0; i < N; i++) scanf("%lld", &V[i]);
  H = (int)ceil(log2(N));
  H = 1 << (H + 1);
  vector<LL> T(H);
  init(V, T, 1, 0, N - 1);

  int A, B;
  LL C;
  for (int i = 0; i < M + K; i++) {
    scanf("%d %d %lld", &A, &B, &C);
    if (A == 1)
      update(V, T, 1, 0, N - 1, B - 1, C);
    else if (A == 2)
      printf("%lld\n", query(T, 1, 0, N - 1, B - 1, (int)C - 1));
  }
}

int main() { solve(); }