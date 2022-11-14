#include <iostream>
#include <queue>
using namespace std;
int N, R;

int main() {
  int T;
  scanf("%d", &N);
  priority_queue<int, vector<int>, greater<int>> Q;
  for (int i = 0; i < N; i++) {
    scanf("%d", &T);
    Q.push(T);
  }
  for (int i = 0; i < N; i++) {
    R += Q.top() * (N - i);
    Q.pop();
  }

  printf("%d\n", R);
}