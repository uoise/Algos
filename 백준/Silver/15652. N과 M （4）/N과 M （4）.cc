#include <iostream>
int arr[9];

int N, M;
void solve(int dp, int dt = 0) {
  if (dp == M) {
    for (int i = 0; i < M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (dt <= i) {
      arr[dp] = i;
      solve(dp + 1, arr[dp]);
    }
  }
}

int main() {
  int i;
  scanf("%d", &N);
  scanf("%d", &M);
  while (i < M) arr[i++] = 0;
  solve(0);
}