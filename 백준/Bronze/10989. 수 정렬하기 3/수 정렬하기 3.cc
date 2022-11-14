#include <iostream>
int V[10000], N, T;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &T);
    V[T - 1]++;
  }
  for (int i = 1; i < 10001; i++)
    for (int j = 0; j < V[i - 1]; j++) {
      printf("%d\n", i);
    }
}