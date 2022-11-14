#include <iostream>
#include <stack>
#define MX 1000001
int N, V[MX], R[MX];
std::stack<int> S;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &V[i]);
  for (int i = N; i > 0; i--) {
    while (!S.empty() && V[i] >= S.top()) S.pop();
    R[i] = S.empty() ? -1 : S.top();
    S.push(V[i]);
  }
  for (int i = 1; i <= N; i++) printf("%d ", R[i]);
  printf("\n");
}