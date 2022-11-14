#include <cmath>
#include <iostream>
using namespace std;
void solve() {
    int T;
    cin >> T;
    for (int testCase = 0; testCase < T; testCase++) {
        unsigned int h, w, n, y, x;
        cin >> h >> w >> n;
        y = n % h;
        if (y == 0) y = h;
        x = (int)ceil((float)n / h);
        printf("%d%02d\n", y, x);
    }
}

int main() { solve(); }