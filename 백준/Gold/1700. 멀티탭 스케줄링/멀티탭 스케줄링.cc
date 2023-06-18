#include <cstdio>
#include <unordered_set>

std::unordered_set<int> s;
int n, k, v[101], r;
void opt(const int& pos) {
  ++r;
  int max = -1, idx = -1;
  for (auto it = s.begin(); it != s.end(); it++) {
    int fst = 101;
    for (int i = pos; i < k; i++) {
      if (v[i] == *it) {
        fst = i;
        break;
      }
    }

    if (fst == 101) {
      s.erase(it);
      return;
    }
    if (fst > max) max = fst, idx = *it;
  }
  s.erase(s.find(idx));
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; i++) scanf("%d", &v[i]);
  for (int i = 0; i < k; i++) {
    if (s.find(v[i]) != s.end()) continue;
    if (s.size() >= n) opt(i + 1);
    s.insert(v[i]);
  }

  printf("%d", r);
}