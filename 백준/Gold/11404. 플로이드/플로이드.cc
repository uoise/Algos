#include <cstring>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int INF = 0x3F3F3F3F;
  int N, M, a, b, c;
  cin >> N >> M;
  int dst[N + 1][N + 1];
  memset(dst, 0x3F, sizeof(dst));
    
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    if (dst[a][b] > c) dst[a][b] = c;
  }

  // FWS
  for (int i = 1; i <= N; i++)
    for (int x = 1; x <= N; x++)
      for (int y = 1; y <= N; y++)
        if (x != y) dst[x][y] = min(dst[x][y], dst[x][i] + dst[i][y]);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << ((dst[i][j] == INF) ? 0 : dst[i][j]) << " ";
    cout << '\n';
  }
}
