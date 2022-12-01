#include <cstdio>
#include <queue>

int dv[101][2];
char vv[101][101], n;
constexpr char xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::deque<std::pair<int, int>> q;

void inp() {
  int k, x, y;
  char c;
  scanf("%d\n%d", &n, &k);
  while (k--) {
    scanf("%d %d", &y, &x);
    vv[y][x] = 1;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %c", &dv[i][0], &c);
    dv[i][1] = (c == 'L' ? 1 : 0);
  }
}

int sol() {
  int y = 1, x = 1, t = 0, d = 0, idx = 0;
  q.push_front({y, x});
    
  while (1) {
    if ((!y || !x || y > n || x > n) || (vv[y][x] == 2)) break;
    if (!vv[y][x]) {
      auto bp = q.back();
      q.pop_back();
      vv[bp.first][bp.second] = 0;
    }
    vv[y][x] = 2;
    q.push_front({y, x});

    if ((idx < 101) && (t == dv[idx][0])) {
      d += (dv[idx++][1] ? 3 : 1);
      d %= 4;
    }
    y += yy[d], x += xx[d], t++;
  }
  return t;
}

int main() {
  inp();
  printf("%d", sol());
}