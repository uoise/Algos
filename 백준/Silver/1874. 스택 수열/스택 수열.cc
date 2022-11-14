#include <iostream>
#include <stack>
#include <vector>
int N, V[100001], C = 1;
std::stack<int> S;
std::vector<bool> R;
bool solve() {
  S.push(0);
  for (int i = 1; i <= N; i++) {
    while (V[i] > S.top()) {
      S.push(C++);
      R.push_back(true);
    }
    if (V[i] == S.top()) {
      S.pop();
      R.push_back(false);
    } else
      return false;
  }
  for (auto r : R) printf(r ? "+\n" : "-\n");
  return true;
}
int main() {
  scanf("%d", &N);
  for (size_t i = 1; i <= N; i++) scanf("%d", &V[i]);
  if (!solve()) printf("NO\n");
}
