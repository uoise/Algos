#include <cstdio>
int main() { long long n, r = 1; scanf("%lld", &n); while (n) r *= n--; printf("%lld", r); }