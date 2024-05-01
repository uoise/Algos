#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

constexpr int EXC = 1, MO = 1e6, INF = 1e9;
const string OPS[] = {
    "QUIT", "END", "NUM", "POP", "INV", "DUP",
    "SWP",  "ADD", "SUB", "MUL", "DIV", "MOD",
};

int sti() {
  string s;
  cin >> s;
  for (int i = 0; i < 12; i++)
    if (OPS[i] == s) return i - 1;
  return -1;
}

struct gs {
  bool ERR;
  int v[1001], t;
  int ov[MO], os;
  int bv[MO], bs, bi;
  void init() { ERR = 0, os = 0, bs = 0, bi = 0; }
  void addOp(int x) { ov[os++] = x; }
  void addOr(int x) { bv[bs++] = x; }
  bool num(const int x) { v[++t] = x; return 0; }
  bool pop() { --t; return 0; }
  bool inv() { v[t] = -v[t]; return 0; }
  bool dup() { v[++t] = v[t]; return 0; }
  bool swp() { swap(v[t], v[t - 1]); return 0; }
  bool aluOp(ll (*op)(ll, ll)) {
    if (t < 2) return EXC;
    const ll r = op(v[t - 1], v[t]);
    if (abs(r) > INF) return EXC;
    v[--t] = r;
    return 0;
  }
  bool add() { return aluOp([](ll a, ll b) { return a + b; }); }
  bool sub() { return aluOp([](ll a, ll b) { return a - b; }); }
  bool mul() { return aluOp([](ll a, ll b) { return a * b; }); }
  bool div() {
    if (t < 2 || !v[t]) return EXC;
    const int r = abs(v[t - 1]) / abs(v[t]);
    if (abs(r) > INF) return EXC;
    v[--t] = r * ((v[t - 1] < 0) ^ (v[t] < 0) ? -1 : 1);
    return 0;
  }
  bool mod() {
    if (t < 2 || !v[t]) return EXC;
    const int r = abs(v[t - 1]) % abs(v[t]);
    if (abs(r) > INF) return EXC;
    v[--t] = r * ((v[t - 1] < 0) ? -1 : 1);
    return 0;
  }
  
  void expect() {
    int stkCnt = 1;
    for (int o = 0; o < os; o++) {
      if (ov[o] == 1) {
        ++stkCnt;
      } else if (ov[o] < 5) {
        if (stkCnt < 1) {
          ERR = 1;
          return;
        }
        if (ov[o] == 2) --stkCnt;
        else if (ov[o] == 4) ++stkCnt;
      } else {
        if (stkCnt < 2) {
          ERR = 1;
          return;
        }
        if(ov[o] != 5) --stkCnt;
      }
    }
    ERR = stkCnt != 1;
  }

  bool run(const int& x) {
    switch (x) {
      case 1: return num(bv[bi++]);
      case 2: return pop();
      case 3: return inv();
      case 4: return dup();
      case 5: return swp();
      case 6: return add();
      case 7: return sub();
      case 8: return mul();
      case 9: return div();
      case 10: return mod();
    }
    return 1;
  }

  void sol(const int& x) {
    t = 1;
    v[t] = x, bi = 0;
    for (int o = 0; o < os; o++) {
      if (!run(ov[o])) continue;
      cout << "ERROR\n";
      return;
    }
    cout << v[t] << '\n';
  }
};

gs g;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  int o, x;
  while (1) {
    g.init();
    o = sti();
    if (o == -1) break;
    while (o) {
      g.addOp(o);
      if (o == 1) {
        cin >> x;
        g.addOr(x);
      }
      o = sti();
    }
    g.expect();
    cin >> o;
    while (o--) {
      cin >> x;
      if (g.ERR) cout << "ERROR\n";
      else g.sol(x);
    }
    cout << '\n';
  }
}