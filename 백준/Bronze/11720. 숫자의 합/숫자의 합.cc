#include <iostream>
using namespace std;

void solve() {
    int N, r = 0;
    char c;
    cin >> N;
    cin.ignore(1);
    while (true) {
        cin.get(c);
        if (cin.eof()) break;
        if (c == '\n') break;
        r += c - '0';
    }
    cout << r << '\n';
}

int main() { solve(); }