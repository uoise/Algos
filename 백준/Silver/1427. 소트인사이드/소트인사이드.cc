#include <iostream>
using namespace std;
unsigned int arr[10];

void solve() {
  int i;
  while ((i = cin.get()) != EOF) {
    if (i == '\n') break;
    arr[i-'0']++;
  }

  for (i = 9; i >= 0; i--)
    while (arr[i]--) cout << i;
}

int main() { solve(); }