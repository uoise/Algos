#include <iostream>
#include <vector>
using namespace std;
vector<int> A, T;
int N, K, C, R = -1;

void merge(const int p, const int q, const int r) {
  int i = p, j = q + 1, t = 1;
  while (i <= q && j <= r) T[t++] = (A[i] <= A[j]) ? A[i++] : A[j++];
  while (i <= q) T[t++] = A[i++];
  while (j <= r) T[t++] = A[j++];
  i = p, t = 1;
  while (i <= r) {
    if (++C == K) R = T[t];
    A[i++] = T[t++];
  }
}

void merge_sort(const int p, const int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;
  A.resize(N + 1);
  T.resize(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  merge_sort(1, N);
  cout << R;
}