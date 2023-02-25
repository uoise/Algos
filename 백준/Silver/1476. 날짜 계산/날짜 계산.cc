#include <cstdio>
int e, s, m, ee, ss, mm, r;
int main() {
  scanf("%d %d %d", &e, &s, &m);
  --e, --s, --m, ++r;
  while (e != ee || s != ss || m != mm) ++ee %= 15, ++ss %= 28, ++mm %= 19, ++r;
  printf("%d", r);
}