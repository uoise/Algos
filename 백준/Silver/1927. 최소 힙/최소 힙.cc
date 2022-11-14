#include <functional>
#include <iostream>
#include <queue>
int n, x;
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (x > 0)
      pq.push(x);
    else if (pq.empty())
      printf("0\n");
    else {
      printf("%d\n", pq.top());
      pq.pop();
    }
  }
}