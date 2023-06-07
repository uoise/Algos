#include <deque>
#include <iostream>
#include <stack>

using namespace std;

stack<int> fq;
deque<int> bq, tq;
int n, c, v[2001], r, s, l;
char op;
void bck() {
  if (bq.empty()) return;
  fq.push(r);
  r = bq.front();
  bq.pop_front();
}

void fwd() {
  if (fq.empty()) return;
  bq.push_front(r);
  r = fq.top();
  fq.pop();
}

void cpr() {
  l = 0;
  while (!bq.empty()) {
    s -= v[bq.front()];
    if (l != bq.front()) {
      s += v[bq.front()];
      tq.push_front(bq.front());
    }
    l = bq.front();
    bq.pop_front();
  }
  while (!tq.empty()) {
    bq.push_front(tq.front());
    tq.pop_front();
  }
}

void acs(const int& tgt) {
  while (!fq.empty()) {
    s -= v[fq.top()];
    fq.pop();
  }
  if (r) bq.push_front(r);
  r = tgt;
  s += v[r];
  while (s > c) {
    s -= v[bq.back()];
    bq.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q, ov;
  cin >> n >> q >> c;
  for (int i = 1; i <= n; i++) cin >> v[i];
  while (q--) {
    cin >> op;
    if (op == 'B')
      bck();
    else if (op == 'F')
      fwd();
    else if (op == 'C')
      cpr();
    else {
      cin >> ov;
      acs(ov);
    }
  }

  cout << r << '\n';
  if (bq.empty()) {
    cout << -1;
  } else {
    while (!bq.empty()) {
      cout << bq.front() << ' ';
      bq.pop_front();
    }
  }
  cout << '\n';
  if (fq.empty()) {
    cout << -1;
  } else {
    while (!fq.empty()) {
      cout << fq.top() << ' ';
      fq.pop();
    }
  }
}