#include <iostream>
int N, K, T, S, C;
struct RQ {
  int value;
  RQ* next;
  RQ(int value) : value(value), next(nullptr) {}
  int pop_next() {
    int res = next->value;
    RQ* tmp = next->next;
    next = tmp;
    return res;
  }
};

int main() {
  scanf("%d %d", &N, &K);
  K--;
  RQ* rq = new RQ(1);
  RQ* p = rq;
  for (size_t i = 2; i <= N; i++) {
    p->next = new RQ(i);
    p = p->next;
  }
  p->next = rq;
  int R[N];
  S = N;
  while (S > 1) {
    if (T == K) {
      R[C++] = p->pop_next();
      S--;
      T = 0;
    } else {
      T++;
      p = p->next;
    }
  }

  printf("<");
  for (size_t i = 0; i < C; i++) printf("%d, ", R[i]);
  printf("%d>\n", p->value);
}