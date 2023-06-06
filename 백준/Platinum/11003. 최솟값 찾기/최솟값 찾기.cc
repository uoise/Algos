#include <deque>
#include <iostream>
using namespace std;
std::deque<int> w;
int n, l, v[5000002];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    if (!w.empty() && w.front() <= i - l) w.pop_front();
    while (!w.empty() && v[w.back()] > v[i]) w.pop_back();
    w.push_back(i);
    cout << v[w.front()] << ' ';
  }
}