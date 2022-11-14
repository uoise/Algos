#include <iostream>
using namespace std;
constexpr int MX = 10001;
bool dp[MX + 1];
void clc(int n) {
  int r = n;
  while (n) {
    r += n % 10;
    n /= 10;
  }
  if (r < MX && !dp[r]) {
    clc(r);
    dp[r] = 1;
  }
}
void sol() {
  for (int i = 1; i < MX; i++)
    if (!dp[i]) clc(i);

  for (int i = 1; i < MX; i++)
    if (!dp[i]) cout << i << '\n';
}
int main() { sol(); }