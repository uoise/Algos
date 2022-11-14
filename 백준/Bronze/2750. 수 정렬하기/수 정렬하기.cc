#include <iostream>
using namespace std;
bool arr[2001];
void solve() {
  int N, i, t;
  cin >> N;

  for (i = 0; i < N; i++) {
    cin >> t;
    arr[t + 1000] = true;
  }
  i = 0;
  while (N != 0) {
    if (arr[i]) {
      cout << i - 1000 << '\n';
      --N;
    }
    i++;
  }
}

int main() { solve(); }