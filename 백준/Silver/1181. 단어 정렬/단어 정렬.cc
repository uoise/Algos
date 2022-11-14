#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Prio {
 public:
  string s;
  uint32_t length;
  Prio(string s) {
    this->s = s;
    length = s.length();
  }
};

bool operator<(const Prio& a, const Prio& b) {
  if ((a.length < b.length) || ((a.length == b.length) && (a.s < b.s))) return true;
  return false;
}

void solve() {
  int N, i;
  string ss;
  bool dupFlag;
  vector<Prio> v;
  cin >> N;

  while (N--) {
    cin >> ss;
    dupFlag = false;
    for (i = 0; i < v.size(); i++)
      if (ss == v[i].s) {
        dupFlag = true;
        break;
      }
    if (!dupFlag) v.push_back(Prio(ss));
  }

  sort(v.begin(), v.end());

  for (i = 0; i < v.size(); i++) cout << v[i].s << '\n';
}

int main() { solve(); }
