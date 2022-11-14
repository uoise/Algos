#include <iostream>
using namespace std;
int arr[20000001];
void solve() {
  int N, t;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &t);
    arr[t + 10000000]++;
  }

  scanf("%d", &N);
  while (N--) {
    scanf("%d", &t);
    printf("%d ", arr[t + 10000000]);
  }
  printf("\n");
}

int main() { solve(); }