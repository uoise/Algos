#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

queue<string> q, nq;
unordered_set<string> s;
int siz;
int bfs(string n, int k) {
  if (k && (siz == 1 || siz == 2 && n[1] == '0')) return -1;
  int r = -1;
  q.push(n);
  for (int i = 0; i < k; i++) {
    while (!q.empty()) {
      string c = q.front();
      q.pop();
      for (int i = 0; i < siz; i++) {
        for (int j = i + 1; j < siz; j++) {
          swap(c[j], c[i]);
          if (s.find(c) == s.end() && c[0] != '0') {
            nq.push(c);
            s.insert(c);
          }
          swap(c[i], c[j]);
        }
      }
    }
    q = nq;
    nq = queue<string>();
    s = unordered_set<string>();
  }

  while (!q.empty()) {
    r = max(stoi(q.front()), r);
    q.pop();
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string n;
  int k;
  cin >> n >> k;
  siz = n.length();
  cout << bfs(n, k);
}