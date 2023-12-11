#include <cstdio>

int r[11], x;
int main() {
  for (int i = 0; i < 2047; i++) {
    for (int j = 0; j < 11; j++) {
      scanf("%d", &x);
      r[j] ^= x;
    }
  }

  for (int i = 0; i < 11; i++) printf("%d ", r[i]);
}