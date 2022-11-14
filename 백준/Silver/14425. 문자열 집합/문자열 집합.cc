#include <iostream>
#include <set>
void solve() {
  int N, M, i, r = 0;
  std::string s;
  std::set<std::string> ss;
  scanf("%d", &N);
  scanf("%d", &M);
  for (i = 0; i < N; i++) {
    std::cin >> s;
    ss.insert(s);
  }
  for (i = 0; i < M; i++) {
    std::cin >> s;
    if (ss.count(s)) r++;
  }
  printf("%d\n", r);
}

int main() { solve(); }