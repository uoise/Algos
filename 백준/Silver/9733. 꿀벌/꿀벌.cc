#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

string sv[7] = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
int vv[7];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    stringstream ss(s);
    while (ss >> s) {
      for (int j = 0; j < 7; j++)
        if (s == sv[j]) vv[j]++;
      cnt++;
    }
  }

  for (int i = 0; i < 7; i++) {
    cout << sv[i] << " " << vv[i] << " ";
    cout << fixed << setprecision(2) << (double)vv[i] / cnt << "\n";
  }
  cout << "Total " << cnt << " 1.00\n";
}