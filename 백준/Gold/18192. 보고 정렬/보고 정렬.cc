#include "bogoSort.h"

bool chk(std::vector<int> &v) {
  for (int i = 0; i < v.size(); i++) if (i != v[i]) return 0;
  return 1;
}

void sort_array(int N) {
  std::vector<int> v = copy_array();
  int s = 0, e = N - 1;
  while (!chk(v)) {
    while (v[s] != s) {
      for (int i = s; i < N; i++) {
        if (v[i] != s) continue;
        e = i;
        break;
      }
      shuffle_array(s, e);
      v = copy_array();
    }
    ++s;
  }
}