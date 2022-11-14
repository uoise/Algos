#include <iostream>
using namespace std;
int N, STK[10001], CNT;

void push(const int &X) { STK[CNT++] = X; }
int pop() { return CNT > 0 ? STK[--CNT] : -1; }
int size() { return CNT; }
int empty() { return CNT == 0 ? 1 : 0; }
int top() { return CNT > 0 ? STK[CNT - 1] : -1; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string CMD;
  cin >> N;
  while (N--) {
    cin >> CMD;
    if (CMD == "push") {
      int T;
      cin >> T;
      push(T);
    } else {
      if (CMD == "pop")
        cout << pop();
      else if (CMD == "size")
        cout << size();
      else if (CMD == "empty")
        cout << empty();
      else if (CMD == "top")
        cout << top();
      cout << '\n';
    }
  }
}