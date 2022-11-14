#include <iostream>
#include <queue>
using namespace std;
int n, x;

struct MQ {
  int mid;
  priority_queue<int> lq;
  priority_queue<int, vector<int>, greater<int>> rq;
  MQ(int inp) : mid(inp) {
    printf("%d\n", mid);
    lq.push(-99999);
    rq.push(99999);
  }

  void push(int inp) {
    if (lq.size() == rq.size()) {
      if (inp < mid) {
        rq.push(mid);
        lq.push(inp);
        mid = lq.top();
        lq.pop();
      } else
        rq.push(inp);
    } else {  // greater rq
      if (inp > mid) {
        lq.push(mid);
        rq.push(inp);
        mid = rq.top();
        rq.pop();
      } else {
        lq.push(inp);
      }
    }
    printf("%d\n", mid);
  }
};

int main() {
  scanf("%d %d", &n, &x);
  MQ mq(x);
  for (int i = 1; i < n; i++) {
    scanf("%d", &x);
    mq.push(x);
  }
}