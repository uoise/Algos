#include <iostream>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string istr, bstr, stk = "";
  cin >> istr >> bstr;
  const int bmb = bstr.size();
  const char bec = bstr[bmb - 1];
  for (const char& cur : istr) {
    stk.push_back(cur);
    if ((stk.size() >= bmb) && (cur == bec)) {
      int bnt = 0;
      for (int i = 1; i <= bmb; i++) {
        if (bstr[bmb - i] != stk[stk.size() - i]) break;
        bnt++;
      }
      if (bnt == bmb)
        while (bnt--) stk.pop_back();
    }
  }
  cout << (stk.empty() ? "FRULA" : stk);
}