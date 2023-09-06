#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

constexpr int MX = 1001;

queue<int> q[MX], sq, gr;
unordered_map<string, int> ns;
priority_queue<string, vector<string>, greater<>> pq;
priority_queue<int> rq[MX];
string sv[MX];
int n, v[MX];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  string x, y;
  int m = 0, s, e;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    pq.push(x);
  }
  while (!pq.empty()) {
    ns.insert({pq.top(), m});
    sv[m++] = pq.top();
    pq.pop();
  }

  cin >> m;
  while (m--) {
    cin >> x >> y;
    s = ns[x], e = ns[y];
    ++v[s];
    q[e].push(s);
  }

  for (int i = 0; i < n; i++) {
    if (v[i]) continue;
    gr.push(i);
    sq.push(i);
    v[i] = -1;
  }

  while (!sq.empty()) {
    s = sq.front();
    sq.pop();
    while (!q[s].empty()) {
      e = q[s].front();
      q[s].pop();
      if (--v[e]) continue;
      rq[s].push(-e);
      sq.push(e);
    }
  }

  cout << gr.size() << '\n';
  while (!gr.empty()) {
    cout << sv[gr.front()] << ' ';
    gr.pop();
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    cout << sv[i] << ' ' << rq[i].size() << ' ';
    while (!rq[i].empty()) {
      cout << sv[-rq[i].top()] << ' ';
      rq[i].pop();
    }
    cout << '\n';
  }
}