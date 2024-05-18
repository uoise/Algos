#include <cstdio>
#include <vector>

std::vector<int> v[2];
int n;
int main() {
  scanf("%d", &n);
  if (n % 3 == 2) v[0].push_back(1), v[1].push_back(2);
  for (int i = n; i >= 3; i -= 3) {
    v[0].push_back(i - 1), v[0].push_back(i - 2);
    v[1].push_back(i);
  }

  for (auto c : v) {
    printf("%lld\n", c.size());
    for (int i : c) printf("%d ", i);
    printf("\n");
  }
}