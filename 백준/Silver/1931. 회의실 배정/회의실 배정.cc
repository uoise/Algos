#include <iostream>
#include <queue>
unsigned int N, R, A;

struct Prio {
  unsigned int x, y;
  Prio(unsigned int x, unsigned int y) : x(x), y(y) {}
  bool operator<(const Prio a) const {
    return (y == a.y) ? (x > a.x) : (y > a.y);
  }
};

int main() {
  int x, y;
  scanf("%d", &N);
  std::priority_queue<Prio> Q;
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &x, &y);
    Q.push(Prio(x, y));
  }

  while (!Q.empty()) {
    if (R <= Q.top().x) {
      R = Q.top().y;
      A++;
    }
    Q.pop();
  }
  printf("%d\n", A);
}