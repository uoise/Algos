#include <iostream>
int K, V[100001], R, cnt;

int main() {
  scanf("%d", &K);
  for (int i = 0; i < K; i++) {
    scanf("%d", &V[cnt]);
    if (V[cnt] == 0)
      V[--cnt] = 0;
    else
      cnt++;
  }
  for (int i = 0; i < cnt; i++) R += V[i];
  printf("%d\n", R);
}