#include <iostream>
int arr[16];
int N, r;
bool flag;
int abs(int a) { return a > 0 ? a : a * -1; }

void solve(int dp) {
  if (dp == N) {
    r++;
    return;
  }
  for (int i = 0; i < N; i++) {
    flag = true;
    for (int j = 0; j < dp; j++) {
      if ((arr[j] == i) || (abs(dp - j) == abs(i - arr[j]))) {
        flag = false;
        break;
      }
    }
    if (flag) {
      arr[dp] = i;
      solve(dp + 1);
    }
  }
}
int main() {
  scanf("%d", &N);
  solve(0);
  printf("%d", r);
}