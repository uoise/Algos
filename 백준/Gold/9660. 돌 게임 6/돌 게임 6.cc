#include <cstdio>
long long n;
int main() {
  scanf("%lld", &n);
  printf("%s", !(n % 7 == 2 || !(n % 7)) ? "SK" : "CY");
}