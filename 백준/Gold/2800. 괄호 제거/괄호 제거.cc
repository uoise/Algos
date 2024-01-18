#include <cstring>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
stack<int> stk;
pair<int, int> v[11];
set<string> r;
string s;
bool bi[201];
int n, m;
void btr(vector<int>& cur, int idx) {
  if (idx == m) {
    if (cur.empty()) return;
    memset(bi, 0, sizeof bi);
    for (const int& i : cur) {
      const auto& [l, r] = v[i];
      bi[l] = bi[r] = 1;
    }

    string ss = "";
    for (int i = 0; i < n; i++)
      if (!bi[i]) ss.push_back(s[i]);
    r.insert(ss);
    return;
  }

  btr(cur, idx + 1);
  cur.push_back(idx);
  btr(cur, idx + 1);
  cur.pop_back();
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else if (s[i] == ')') {
      v[m++] = {stk.top(), i};
      stk.pop();
    }
  }
  vector<int> c;
  btr(c, 0);
  for (const auto& ss : r) cout << ss << '\n';
}