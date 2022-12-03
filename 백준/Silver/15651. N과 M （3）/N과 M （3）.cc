#include <iostream>
int arr[9];
bool bar[9];
int N, M;
void solve(int dp, int dt = 0) {
  if (dp == M) {
    for (int i = 0; i < M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  for (int i = 0; i < N; i++) {
    arr[dp] = i + 1;
    bar[i] = true;
    solve(dp + 1, arr[dp]);
    bar[i] = false;
  }
}


int main() {
  int i;
  scanf("%d", &N);
  scanf("%d", &M);
  while (i < M) arr[i++] = 0;
  solve(0);
}