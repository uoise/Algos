#include <iostream>
using namespace std;
void solve() {
    int T, r = 0;
    cin >> T;
    for (int testCase = 0; testCase < T; testCase++) {
        int n;
        bool flag = true;
        cin >> n;
        if (n == 1) flag = false;
        for (int i = 2; i <= n / 2 ; i++)
            if (n % i == 0) {
                flag = false;
            }
        if (flag) r++;
    }
    cout << r << endl;
}
int main() { solve(); }