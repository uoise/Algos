#include <iostream>
#include <vector>

using namespace std;

bool bv[13];
int vv[50][50], rv[100][13], N, M, res;
vector<pair<int, int>> hp, mp;

void btr(int idx, int cnt) {
  bv[idx] = 1;
  if (cnt == M) {
    int sum = 0;
    for (int h = 0; h < hp.size(); h++) {
      int mn = 2e9;
      for (int m = 0; m < mp.size(); m++) {
        if (!bv[m]) {
          rv[h][m] =
              abs(hp[h].first - mp[m].first) + abs(hp[h].second - mp[m].second);
          mn = min(mn, rv[h][m]);
        }
      }
      if (mn == 2e9) return;
      sum += mn;
    }
    res = min(sum, res);
  } else {
    for (int i = idx + 1; i < mp.size(); i++) {
      btr(i, cnt + 1);
    }
  }
  bv[idx] = 0;
}

int sol() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> vv[i][j];
      if (vv[i][j] & 1)
        hp.push_back({i, j});
      else if (vv[i][j] & 2)
        mp.push_back({i, j});
    }
  }
  M = mp.size() - M;
  if (!M) {
    res = 0;
    for (int h = 0; h < hp.size(); h++) {
      int mn = 2e9;
      for (int m = 0; m < mp.size(); m++) {
        rv[h][m] =
            abs(hp[h].first - mp[m].first) + abs(hp[h].second - mp[m].second);
        mn = min(mn, rv[h][m]);
      }
      res += mn;
    }
    return res;
  }
  res = 2e9;
  for (int i = 0; i < mp.size(); i++) btr(i, 1);
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> M;
  cout << sol();
}
