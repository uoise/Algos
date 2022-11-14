#include <iostream>
bool arr[100000000];

void solve() {
  unsigned int N, M, t, i;
  scanf("%d", &N);
  scanf("%d", &M);
  i = N + M;

  while (N--) {
    scanf("%d", &t);
    arr[t] = true;
  }
  while (M--) {
    scanf("%d", &t);
    if (arr[t]) i -= 2;
  }
  printf("%d", i);
}

int main() { solve(); }