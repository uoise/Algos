#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

constexpr int yy[] = {1, 0, -1, 0, 1, 1, -1, -1},
              xx[] = {0, 1, 0, -1, 1, -1, 1, -1};

unordered_map<string, int> ss;
char sv[10][11];
int n, m, l;
void sol(const int& y, const int& x, const string& s) {
  if (s.length() > 5) return;
  ++ss[s];
  int ny, nx;
  for (int i = 0; i < 8; i++) {
    ny = (y + yy[i] + n) % n, nx = (x + xx[i] + m) % m;
    sol(ny, nx, s + sv[ny][nx]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int y, x, k, r;
  string rs = "";
  cin >> n >> m >> k;
  for (y = 0; y < n; y++) cin >> sv[y];

  for (y = 0; y < n; y++)
    for (x = 0; x < m; x++) sol(y, x, rs + sv[y][x]);

  while (k--) {
    cin >> rs;
    cout << ss[rs] << '\n';
  }
}