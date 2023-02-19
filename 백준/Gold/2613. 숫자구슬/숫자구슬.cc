#include <cstdio>

int n, m, v[301], r[301], b, e, s, c;
bool clc(const int& mxx) {
  s = 0, c = 1;
  for (int i = 0; i < n; i++) {
    if (s + v[i] <= mxx)
      s += v[i];
    else
      s = v[i], ++c;
  }
  return m >= c;
}

void sol() {
  int mid, res, idx = 0;
  while (b <= e) {
    mid = (b + e) / 2;
    if (clc(mid))
      res = mid, e = mid - 1;
    else
      b = mid + 1;
  }

  printf("%d\n", res);

  s = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (s + v[i] <= res) {
      ++c, s += v[i];
    } else {
      r[idx++] = c;
      c = 1, s = v[i];
    }
  }

  r[idx++] = c;

  while (idx < m) {
    for (int i = idx - 1; i >= 0; i--) {
      if (r[i] > 1) {
        for (int j = idx - 1; j > i; j--) r[j + 1] = r[j];
        r[i + 1] = 1, --r[i], ++idx;
        break;
      }
    }
  }
  for (int i = 0; i < idx; i++) printf("%d ", r[i]);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    b = v[i] > b ? v[i] : b;
  }
  e = b * n;
  sol();
}