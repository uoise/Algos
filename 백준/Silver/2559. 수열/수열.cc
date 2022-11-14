#include <iostream>
int V[100001], N, K;
void solve() {
  int beg = 1, end = K, tmp = 0, res;
  for (int i = beg; i <= end; i++) tmp += V[i];
  res = tmp;
  for (int i = 2; i <= N - K + 1; i++) {
    tmp -= V[beg++];
    tmp += V[++end];
    res = (res > tmp) ? res : tmp;
  }
  printf("%d\n", res);
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) scanf("%d", &V[i]);
  solve();
}