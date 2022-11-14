#include <iostream>
#include <queue>
int n, x;
struct ins {
  int val, abs;
  ins(int v) : val(v), abs(v > 0 ? v : v * -1) {}
};
bool operator<(const ins& a, const ins& b) {
  return a.abs == b.abs ? a.val > b.val : a.abs > b.abs;
}
std::priority_queue<ins> pq;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (x != 0)
      pq.push(x);
    else if (pq.empty())
      printf("0\n");
    else {
      printf("%d\n", pq.top().val);
      pq.pop();
    }
  }
}