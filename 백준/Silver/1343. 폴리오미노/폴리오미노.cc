#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string B, T, R;
  cin >> B;
  for (int i = 0; i < B.size(); i++) {
    if (B[i] == '.') {
      while (!T.empty()) {
        if (T.size() >= 4) {
          T.erase(0, 4);
          R += "AAAA";
        } else if (T.size() == 2) {
          T.erase(0, 2);
          R += "BB";
        } else {
          cout << "-1";
          return 0;
        }
      }
      R += B[i];
    } else
      T += B[i];
  }
  while (!T.empty()) {
    if (T.size() >= 4) {
      T.erase(0, 4);
      R += "AAAA";
    } else if (T.size() == 2) {
      T.erase(0, 2);
      R += "BB";
    } else {
      cout << "-1";
      return 0;
    }
  }
  cout << R;
  return 0;
}