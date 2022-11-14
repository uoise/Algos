#include <iostream>
using namespace std;

void solve() {
    uint32_t n, r = 1;
    cin >> n;
    while (n > 0) r *= n--;

    cout << r << endl;
}
int main() { solve(); }