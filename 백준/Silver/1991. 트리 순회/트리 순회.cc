#include <iostream>
#define ccp pair<char, char>
using namespace std;
int n;
ccp tr[27];

void pre(const char cur) {
  cout << cur;
  if (tr[cur - 'A'].first != '.') pre(tr[cur - 'A'].first);
  if (tr[cur - 'A'].second != '.') pre(tr[cur - 'A'].second);
}
void in(const char cur) {
  if (tr[cur - 'A'].first != '.') in(tr[cur - 'A'].first);
  cout << cur;
  if (tr[cur - 'A'].second != '.') in(tr[cur - 'A'].second);
}
void post(const char cur) {
  if (tr[cur - 'A'].first != '.') post(tr[cur - 'A'].first);
  if (tr[cur - 'A'].second != '.') post(tr[cur - 'A'].second);
  cout << cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;

  char x, y, z;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    tr[x - 'A'] = {y, z};
  }
  pre('A');
  cout << '\n';
  in('A');
  cout << '\n';
  post('A');
}
