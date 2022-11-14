#include <iostream>
using namespace std;

void solve() {
  uint32_t N, M, x, y, r1, r2, rm = 65;
  string s;
  cin >> N >> M;
  bool carr[N][M];
  for (y = 0; y < N; y++) {
    cin >> s;
    for (x = 0; x < M; x++) {
      if (s.at(x) == 'B')
        carr[y][x] = true;
      else
        carr[y][x] = false;
    }
  }
  for (uint32_t i = 0; i <= M - 8; i++)
    for (uint32_t j = 0; j <= N - 8; j++) {
      r1 = r2 = 0;
      for (x = i; x < i + 8; x++) {
        for (y = j; y < j + 8; y++) {
          if (carr[y][x] == (bool)((x + y) % 2)) r1++;  // FTFT...
          //   if (carr[y][x] != (bool)((x + y) % 2)) r2++;  // FTFT...
        }
      }
      if (32 < r1) r1 = 64 - r1;
      if (rm > r1) rm = r1;
    }
  cout << rm << '\n';
}

int main() { solve(); }