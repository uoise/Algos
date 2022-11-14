#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// https://book.acmicpc.net/ds/segment-tree
int N, M, H;

void init(vector<int>& tgt, vector<int>& tree, int nod, int beg, int end) {
  if (beg == end) {
    tree[nod] = tgt[beg];
  } else {
    init(tgt, tree, nod * 2, beg, (beg + end) / 2);
    init(tgt, tree, nod * 2 + 1, (beg + end) / 2 + 1, end);
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
  }
}

long query(vector<int>& tree, int nod, int beg, int end, int lft, int rht) {
  if (lft > end || rht < beg) return 0;
  if (lft <= beg && rht >= end) return tree[nod];
  long lres = query(tree, nod * 2, beg, (beg + end) / 2, lft, rht);
  long rres = query(tree, nod * 2 + 1, (beg + end) / 2 + 1, end, lft, rht);
  return lres + rres;
}

void solve() {
  scanf("%d %d", &N, &M);
  vector<int> v(N);
  for (int i = 0; i < N; i++) scanf("%d", &v[i]);
  H = (int)ceil(log2(N));
  H = 1 << (H + 1);
  vector<int> tree(H);
  init(v, tree, 1, 0, N - 1);

  int beg, end;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &beg, &end);
    printf("%ld\n", query(tree, 1, 0, N - 1, beg - 1, end - 1));
  }
}

int main() { solve(); }