#include <cstring>
#include <iostream>
using namespace std;
bool st[21];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  const string cmd[6] = {"add", "remove", "check", "toggle", "all", "empty"};
  int M, x;
  string op;
  cin >> M;
  while (M--) {
    cin >> op;
    if (op == cmd[4])
      memset(st, 1, sizeof(st));
    else if (op == cmd[5])
      memset(st, 0, sizeof(st));
    else {
      cin >> x;
      if (op == cmd[0])
        st[x] = 1;
      else if (op == cmd[1])
        st[x] = 0;
      else if (op == cmd[2])
        cout << st[x] << "\n";
      else
        st[x] = st[x] ? 0 : 1;
    }
  }
}