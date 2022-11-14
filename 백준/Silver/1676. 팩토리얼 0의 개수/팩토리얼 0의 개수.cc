#include <iostream>
void solve() {
  int N, r = 0, i, t;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    t = 5;
    while (t <= i) {
      if (i % t == 0) r++;
      t *= 5;
    }
  }
  printf("%d\n", r);
}
int main() { solve(); }