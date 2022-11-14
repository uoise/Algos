#include <algorithm>
#include <iostream>
using namespace std;

string cut(const string& s, int beg, int end, int rvr = 0) {
  int siz = end - beg;
  string t = s.substr(beg, siz);
  if (rvr) reverse(t.begin(), t.end());
  return t;
}

string sol(const string s) {
  string res = "";
  int cur = 0, blk = 0, opb = 0, clb = 0;
  while (1) {
    blk = s.find(' ', cur);
    opb = s.find('<', cur);
    if (blk == -1 && opb == -1) {
      if (cur < s.size()) res += cut(s, cur, s.size(), 1);
      break;
    } else if (blk == -1 || (opb >= 0 && opb < blk)) {
      clb = s.find('>', opb);
      if (cur < opb) res += cut(s, cur, opb, 1);
      res += (cut(s, opb, clb) + '>');
      cur = clb + 1;
    } else if (opb == -1 || (blk >= 0 && blk < opb)) {
      if (cur < blk) res += (cut(s, cur, blk, 1) + ' ');
      cur = blk + 1;
    }
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  getline(cin, s);
  cout << sol(s);
}
