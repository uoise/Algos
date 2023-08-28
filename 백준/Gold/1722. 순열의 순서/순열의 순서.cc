#include <cstdio>

int n, v[21];
bool b[21];
long long k, f[21] = {1LL};
void pmr() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[j]) continue;
      if (f[n - i] < k) {
        k -= f[n - i];
        continue;
      }
      v[i] = j, b[j] = true;
      break;
    }
  }

  for (int i = 1; i <= n; i++) printf("%d ", v[i]);
}

long long fnd() {
  k = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < v[i]; j++) if (!b[j]) k += f[n - i];
    b[v[i]] = true;
  }

  return k;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i;
  if (m & 1) {
    scanf("%lld", &k);
    pmr();
  } else {
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    printf("%lld", fnd());
  }
}