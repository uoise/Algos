#include <iostream>
using namespace std;

void solve() {
    string s;
    char alpha[26];
    int count[26];
    cin >> s;
    int i;
    for (i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
        count[i] = 0;
    }

    for (i = 0; i < s.length(); i++) {
        if (s.at(i) >= 'a')
            count[s.at(i) - 'a']++;
        else
            count[s.at(i) - 'A']++;
    }

    int m = -1, n = -1;
    for (i = 0; i < 26; i++) {
        if (m < count[i]) {
            m = count[i];
            n = i;
        }
    }
    for (i = 0; i < 26; i++) {
        if (m == count[i] && i != n) {
            cout << "?" << '\n';
            return;
        }
    }
    cout << alpha[n] << '\n';
}
int main() { solve(); }