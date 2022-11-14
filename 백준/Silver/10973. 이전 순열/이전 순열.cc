#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
void sol() {
  vector<int> vv(n);
  for (auto& i : vv) cin >> i;
  if (prev_permutation(vv.begin(), vv.end())) 
    for (const auto& i : vv) cout << i << ' ';
  else
    cout << -1;
}

int main() {
  cin >> n;
  sol();
}