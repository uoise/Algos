#include <cstdio>
#include <string>

using namespace std;
int n, f;
string r;
void sol(string c, int p) {
  if (f) return;
  for (int i = 1; i <= p / 2; i++)
    if (c.substr(p - i, i) == c.substr(p - 2 * i, i)) return;
  if (p == n) {
    r = c, f = 1;
    return;
  }
  for (char i = '1'; i < '4'; i++) sol(c + i, p + 1);
}

int main() {
  scanf("%d", &n);
  sol("", 0);
  printf("%s", r.c_str());
}