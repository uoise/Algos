#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
constexpr int ML = 100;
vector<int> rt[ML + 1], uv(ML + 1), nv(100001);

void rmv(int p) {
  auto& rm = rt[nv[p]];
  rm.erase(remove(rm.begin(), rm.end(), p), rm.end());
  nv[p] = 0;
}

void add(int p, int l) {
  rt[l].push_back(p);
  nv[p] = l;
  uv[l] = 1;
}

void sol() {
  int m, p, l;
  string cmd;
  cin >> m;
  while (m--) {
    cin >> p >> l;
    add(p, l);
  }

  cin >> m;
  while (m--) {
    cin >> cmd;
    if (cmd[0] == 's') {
      cin >> p;
      rmv(p);
    } else if (cmd[0] == 'a') {
      cin >> p >> l;
      if (nv[p]) rmv(p);
      add(p, l);
    } else {
      cin >> l;
      if (l > 0) {
        for (int i = ML; i; i--)
          if (!rt[i].empty()) {
            if (uv[i]) {
              sort(rt[i].begin(), rt[i].end());
              uv[i] = 0;
            }
            cout << rt[i].back() << '\n';
            break;
          }
      } else {
        for (int i = 1; i <= ML; i++)
          if (!rt[i].empty()) {
            if (uv[i]) {
              sort(rt[i].begin(), rt[i].end());
              uv[i] = 0;
            }
            cout << rt[i].front() << '\n';
            break;
          }
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sol();
}