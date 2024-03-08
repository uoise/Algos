#include <algorithm>
#include <bitset>
#include <cstdio>

constexpr char MB[] = {'E', 'S', 'T', 'J'};
char inp[5];
std::bitset<4> v[100001];
int sol() {
  int n, r = 99;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", inp);
    for (int j = 0; j < 4; j++) v[i][j] = inp[j] == MB[j];
  }

  if (n > 16 * 16) return 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = 0; k < n; k++) {
        if (i != k && j != k)
          r = std::min(r, (int)((v[i] ^ v[j]).count() + (v[j] ^ v[k]).count() + (v[k] ^ v[i]).count()));
      }
    }
  }

  return r;
}

int main() {
  int T;
  scanf("%d\n", &T);
  while (T--) printf("%d\n", sol());
}