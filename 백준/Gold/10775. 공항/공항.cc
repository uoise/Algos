#include <cstdio>

int v[100001], g, p, o, r;
int fnd(const int& x) { return (x == v[x]) ? x : (v[x] = fnd(v[x])); }
void mks(int x, int y) { v[fnd(x)] = fnd(y); }
int main() {
  scanf("%d %d", &g, &p);
  for (int i = 0; i <= g; i++) v[i] = i;
  while (p--) {
    scanf("%d", &o);
    if (!(o = fnd(o))) break;
    mks(o, o - 1);
    ++r;
  }
    
  printf("%d", r);
}