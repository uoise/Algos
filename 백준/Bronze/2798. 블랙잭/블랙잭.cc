#include <iostream>
using namespace std;
void solve() {
    uint32_t n, m;
    cin >> n >> m;
    uint32_t arr[n], res = 0;
    for (uint32_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = i + 1; j < n; j++) {
            for (uint32_t k = j + 1; k < n; k++) {
                if (res < arr[i] + arr[j] + arr[k] &&
                    arr[i] + arr[j] + arr[k] <= m)
                    res = arr[i] + arr[j] + arr[k];
            }
        }
    }

    cout << res;
    cout << '\n';
}
int main() { solve(); }