#include <cmath>
#include <iostream>
#include <queue>
unsigned int arr[8001];
using namespace std;

class Prio {
 public:
  int x;
  int count;
  Prio(int x, int count) {
    this->x = x;
    this->count = count;
  }
};
bool operator<(const Prio& a, const Prio& b) {
  if ((a.count < b.count) || ((a.count == b.count) && (a.x > b.x))) return true;
  return false;
}

void solve() {
  int N, t, much, i, mid, min = 4001, max = -4001, sum = 0, muchFlag = 0;
  bool midFlag = true;
  priority_queue<Prio> pq;
  cin >> N;

  for (i = 0; i < N; i++) {
    cin >> t;
    arr[t + 4000]++;
    sum += t;
    if (min > t) min = t;
    if (max < t) max = t;
  }
  t = 0;
  for (i = 0; i < 8001; i++)
    if (arr[i]) {
      pq.push(Prio(i - 4000, arr[i]));
      if (midFlag) {
        t += arr[i];
        if (t >= (N / 2 + 1)) {
          mid = i - 4000;
          midFlag = false;
        }
      }
    }

  t = pq.top().count;

  while (!pq.empty()) {
    if (muchFlag < 2 && pq.top().count == t) {
      much = pq.top().x;
      muchFlag++;
    }
    pq.pop();
  }

  cout << (int)round((float)sum / N) << '\n';
  cout << mid << '\n';
  cout << much << '\n';
  cout << max - min << '\n';
}

int main() { solve(); }