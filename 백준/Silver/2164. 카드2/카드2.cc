#include <iostream>
#include <queue>
int N;
std::deque<int> Q;
int main() {
  scanf("%d", &N);
  for (size_t i = 1; i <= N; i++) Q.push_back(i);
  while (Q.size() > 1) {
    Q.pop_front();
    Q.push_back(Q.front());
    Q.pop_front();
  }
  printf("%d\n", Q.front());
}