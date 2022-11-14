#include <iostream>
using namespace std;
void solve() {
    int T;
    cin >> T;
    for (int testCase = 0; testCase < T; testCase++) {
        unsigned int k, n, r = 0;
        cin >> k >> n;
        unsigned int ar1[n + 1];
        unsigned int ar2[n + 1];
        for (int i = 0; i <= n; i++) ar1[i] = i;

        for (int j = 1; j < k; j++) {
            for (int i = 0; i <= n; i++) ar2[i] = ar1[i];
            for (int i = 1; i <= n; i++)
                for (int l = 1; l < i; l++) ar1[i] += ar2[l];
        }

        for (int i = 1; i <= n; i++) r += ar1[i];
        cout << r << endl;
    }
}
int main() { solve(); }