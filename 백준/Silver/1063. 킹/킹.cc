#include <iostream>

using namespace std;

constexpr int dd[2][8] = {{1, -1, 0, 0, 1, -1, 1, -1}, {0, 0, -1, 1, 1, 1, -1, -1}};
constexpr char cc[4] = {'R', 'L', 'B', 'T'};
int n, o, kp[2], sp[2];
char op[3], kc, sc;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> kc >> kp[1] >> sc >> sp[1] >> n;
  kp[0] = kc - '@', sp[0] = sc - '@';
  for (int i = 0; i < n; i++) {
    cin >> op;
    for (int j = 0; j < 4; j++)
      if (op[0] == cc[j]) o = j;

    if (o < 2) {
      if (op[1] == 'T')
        o += 4;
      else if (op[1] == 'B')
        o += 6;
    }

    for (int i = 0; i < 2; i++) kp[i] += dd[i][o];
    if (!kp[0] || !kp[1] || kp[0] > 8 || kp[1] > 8) {
      for (int i = 0; i < 2; i++) kp[i] -= dd[i][o];
      continue;
    }

    if (kp[0] == sp[0] && kp[1] == sp[1]) {
      for (int i = 0; i < 2; i++) sp[i] += dd[i][o];
      if (!sp[0] || !sp[1] || sp[0] > 8 || sp[1] > 8)
        for (int i = 0; i < 2; i++) kp[i] -= dd[i][o], sp[i] -= dd[i][o];
    }
  }
  cout << (char)('@' + kp[0]) << kp[1] << '\n' << (char)('@' + sp[0]) << sp[1];
}