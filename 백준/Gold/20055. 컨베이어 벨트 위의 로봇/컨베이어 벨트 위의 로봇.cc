#include <cstdio>
#include <deque>

std::deque<int> q;
bool v[101];
int n, k, c, r;
void sft() {
  q.push_front(q.back());
  q.pop_back();
  for (int i = n - 2; i >= 0; i--) v[i + 1] = v[i];
  v[0] = v[n - 1] = 0;
}

void mov() {
  for (int i = n - 2; i; i--) {
    if (!v[i] || v[i + 1] || !q[i + 1]) continue;
    if (!--q[i + 1]) ++c;
    v[i + 1] = i == n - 2 ? 0 : v[i];
    v[i] = 0;
  }
}

void clc() {
  sft();
  mov();
  if (!q[0]) return;
  v[0] = 1;
  if (!--q[0]) ++c;
}

int main() {
  scanf("%d %d", &n, &k);
  int x;
  for (int i = 0; i < n * 2; i++) {
    scanf("%d", &x);
    q.push_back(x);
  }

  while (c < k && ++r) clc();
  printf("%d", r);
}