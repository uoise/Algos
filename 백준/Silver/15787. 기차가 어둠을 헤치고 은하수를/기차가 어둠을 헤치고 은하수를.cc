#include <bitset>
#include <cstdio>
#include <unordered_set>

std::unordered_set<std::bitset<20>> s;
std::bitset<20> v[100001];
int n, m, o, i, x;
int main() {
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &o, &i);
    --i;
    switch (o) {
      case 1:
        scanf("%d", &x);
        v[i][x - 1] = 1;
        break;
      case 2:
        scanf("%d", &x);
        v[i][x - 1] = 0;
        break;
      case 3:
        v[i] <<= 1;
        break;
      case 4:
        v[i] >>= 1;
        break;
    }
  }
  for (i = 0; i < n; i++) s.insert(v[i]);
  printf("%d", s.size());
}