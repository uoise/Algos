#include <iostream>
int arr[9];
bool bar[9];
void solve(const int N, const int M, int dp) {
  if (dp == M) {
    for (int i = 0; i < M; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  for (int i = 0; i < N; i++) {
    if (!bar[i]) {
      arr[dp] = i + 1;
      bar[i] = true;
      solve(N, M, dp + 1);
      bar[i] = false;
    }
  }
}

int main() {
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  solve(N, M, 0);
}