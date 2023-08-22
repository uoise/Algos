#include <deque>
#include <iostream>
#include <string>

using namespace std;

deque<char> fq, bq;
string t, a, r;
bool lck() {
  for (int i = a.length() - 1, j = fq.size() - 1; i >= 0; i--, j--)
    if (a[i] != fq[j]) return false;
  return true;
}

bool rck() {
  for (int i = 0; i < a.length(); i++)
    if (a[i] != bq[i]) return false;
  return true;
}

string sol() {
  const int al = a.length();
  int lp = 0, rp = t.length() - 1, sz;
  while (lp <= rp) {
    while (lp <= rp) {
      fq.push_back(t[lp++]);
      if ((fq.size() >= al) && lck()) {
        sz = al;
        while (sz--) fq.pop_back();
        break;
      }
    }
    while (lp <= rp) {
      bq.push_front(t[rp--]);
      if ((bq.size() >= al) && rck()) {
        sz = al;
        while (sz--) bq.pop_front();
        break;
      }
    }
  }

  while (!fq.empty()) {
    r.push_back(fq.front());
    fq.pop_front();
  }

  while (!bq.empty()) {
    r.push_back(bq.front());
    bq.pop_front();
  }

  while (1) {
    const auto fnd = r.find(a);
    if (fnd >= r.length()) break;
    r.erase(fnd, al);
  }

  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> t;
  cout << sol();
}