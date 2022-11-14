#include <iostream>
#include <map>
using namespace std;

void solve() {
  int N, M, i, t;
  string s;
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;

  map<string, int> dic;
  map<int, string> dic1;
  for (i = 0; i < N; i++) {
    cin >> s;
    dic.insert(make_pair(s, i + 1));
    dic1.insert(make_pair(i + 1, s));
  }
  for (i = 0; i < M; i++) {
    cin >> s;
    if ((s[0] <= '9') && (s[0] > '0')) {
      t = stoi(s);
      cout << dic1[t] << '\n';
    } else {
      cout << dic[s] << '\n';
    }
  }
}

int main() { solve(); }