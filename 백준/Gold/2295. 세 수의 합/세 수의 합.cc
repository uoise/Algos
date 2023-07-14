#include <algorithm>
#include <cstdio>
#include <vector>

std::vector<int> vv;
int n, v[1001], r, s;
int sol() {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      s = v[i] - v[j];
      if (std::binary_search(vv.begin(), vv.end(), s)) return v[i];
    }
  }
  return -1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) vv.push_back(v[i] + v[j]);

  std::sort(v, v + n);
  std::sort(vv.begin(), vv.end());

  printf("%d", sol());
}