#include <iostream>
#include <queue>
using namespace std;
class Prio {
 public:
  uint32_t age;
  uint32_t i;
  string name;
  Prio(uint32_t age, string name, uint32_t i) {
    this->age = age;
    this->name = name;
    this->i = i;
  }
};

bool operator<(const Prio& a, const Prio& b) {
  if ((a.age < b.age) || ((a.age == b.age) && (a.i > b.i))) return false;
  return true;
}

void solve() {
  uint32_t N, i;
  string s;
  priority_queue<Prio> pq;
  cin >> N;
  while (N--) {
    cin >> i;
    cin >> s;
    pq.push(Prio(i, s, N));
  }

  while (!pq.empty()) {
    cout << pq.top().age << " " << pq.top().name << '\n';
    pq.pop();
  }
}
int main() { solve(); }