#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int N, i, j;
  scanf("%d", &N);
  vector<int> v;
  int arr[N];
  for (i = 0; i < N; i++) {
    scanf("%d", &j);
    arr[i] = j;
    v.push_back(arr[i]);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for (i = 0; i < N; i++) {
    printf("%d ", lower_bound(v.begin(), v.end(), arr[i]) - v.begin());
  }
  printf("\n");
}
int main() { solve(); }