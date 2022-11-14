#include <iostream>
#include <queue>
using namespace std;
class Point {
 public:
  int x, y;
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

bool operator<(const Point& a, const Point& b) {
  if ((a.y < b.y) || ((a.y == b.y) && (a.x < b.x))) return false;
  return true;
}
void solve() {
  uint32_t N;
  int x, y;
  priority_queue<Point> pq;
  cin >> N;
  while (N--) {
    cin >> x >> y;
    pq.push(Point(x, y));
  }
  while (!pq.empty()) {
    cout << pq.top().x << " " << pq.top().y << '\n';
    pq.pop();
  }
}

int main() { solve(); }