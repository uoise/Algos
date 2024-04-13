#include <cstdio>

int c[100001];
int main() {
  int n, s, e;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &s, &e);
    ++c[s], ++c[e];
  }

  scanf("%d", &n);
  while (n--) {
    int s, e;
    scanf("%d %d", &s, &e);
    printf("%s\n", (s == 1 ? c[e] > 1 : true) ? "yes" : "no");
  }
}