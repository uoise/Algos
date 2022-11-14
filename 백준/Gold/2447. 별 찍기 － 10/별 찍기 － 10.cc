#include <iostream>
using namespace std;
void solve(uint32_t size) {
    bool res[size][size];
    for (uint32_t y = 0; y < size; y++)
        for (uint32_t x = 0; x < size; x++) res[x][y] = true;
    uint32_t cur = 1;

    while (cur <= size) {
        for (uint32_t y = cur; y < size; y += cur * 3)
            for (uint32_t x = cur; x < size; x += cur * 3)
                for (uint32_t yy = y; yy < y + cur; yy++)
                    for (uint32_t xx = x; xx < x + cur; xx++)
                        res[xx][yy] = false;
        cur *= 3;
    }

    for (uint32_t y = 0; y < size; y++) {
        for (uint32_t x = 0; x < size; x++) {
            res[x][y] ? cout << "*" : cout << " ";
        }
        cout << '\n';
    }
}
int main() {
    uint32_t N;
    cin >> N;
    solve(N);
}