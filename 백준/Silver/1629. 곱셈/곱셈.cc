#include <iostream>
int a, b, c;
long long pow(const int& s) {
  if (s == 0) return 1;
  if (s == 1) return a % c;
  long long r = pow(s / 2) % c;
  if (s % 2 == 0)
    return r * r % c;
  else
    return r * r % c * a % c;
}
int main() {
  scanf("%d %d %d", &a, &b, &c);
  printf("%d", pow(b));
}