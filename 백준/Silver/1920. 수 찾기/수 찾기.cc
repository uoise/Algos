#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, t;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end());
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t;
    cout << binary_search(A.begin(), A.end(), t) << '\n';
  }
}