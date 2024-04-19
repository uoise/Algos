#include <bitset>
#include <cstdio>
std::bitset<1 << 25> s;
long long x;
int main() { while (scanf("%lld", &x) != EOF) if (!s[x]) s[x] = 1, printf("%lld ", x); }