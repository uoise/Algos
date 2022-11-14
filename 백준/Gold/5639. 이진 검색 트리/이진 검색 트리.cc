#include <iostream>
using namespace std;
struct bnt {
  int val;
  bnt *l, *r;
  bnt() : val(0), l(nullptr), r(nullptr) {}
};

void psh(int inp, bnt* cur) {
  if (cur->val == 0) {
    cur->val = inp;
    return;
  }
  if (inp < cur->val) {
    if (cur->l == nullptr) cur->l = new bnt();
    psh(inp, cur->l);
  } else {
    if (cur->r == nullptr) cur->r = new bnt();
    psh(inp, cur->r);
  }
}

void prt(bnt* cur) {
  if (cur->l != nullptr) prt(cur->l);
  if (cur->r != nullptr) prt(cur->r);
  cout << cur->val << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  bnt* root = new bnt();
  int n;
  while (cin >> n) psh(n, root);
  prt(root);
}
