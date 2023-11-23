#include <cstdio>
long long n;
int main() {
  scanf("%lld", &n);
  printf("%s", n & 1 ? "SK" : "CY");
}