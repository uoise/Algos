#include <cstdio>
using ll = long long;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int main() { ll a, b; scanf("%lld %lld", &a, &b); printf("%lld", a * (b / gcd(a, b))); }