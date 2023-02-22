#include <string>
#include <vector>

using namespace std;

bool bv[8][8], uv[8], rv[256];
int usz, bsz;
void btr(int cub, int cuu) {
  bv[cub][cuu] = 0;
  uv[cuu] = 1;
  if (cub + 1 == bsz) {
    int r = 0, t = 1;
    for (int i = 0; i < usz; i++) {
      if (uv[i]) r += t;
      t *= 2;
    }
    rv[r] = 1;
  }

  for (int i = 0; i < usz; i++)
    if (bv[cub + 1][i] && !uv[i]) {
      btr(cub + 1, i);
    }

  bv[cub][cuu] = 1;
  uv[cuu] = 0;
}

int solution(vector<string> user_id, vector<string> banned_id) {
  usz = user_id.size(), bsz = banned_id.size();
  for (int b = 0; b < bsz; b++)
    for (int u = 0; u < usz; u++) {
      if (banned_id[b].size() == user_id[u].size()) {
        bv[b][u] = 1;
        for (int i = 0; i < banned_id[b].size(); i++)
          if (banned_id[b][i] != '*' && banned_id[b][i] != user_id[u][i]) {
            bv[b][u] = 0;
            break;
          }
      }
    }

  for (int i = 0; i < usz; i++)
    if (bv[0][i]) btr(0, i);

  int res = 0;
  for (int i = 0; i < 256; i++)
    if (rv[i]) res++;

  return res;
}