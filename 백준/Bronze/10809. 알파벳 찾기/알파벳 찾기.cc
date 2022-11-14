#include <iostream>
using namespace std;

void solve() {
    string s;
    char alpha[26];
    int count[26];
    uint32_t i = 0;
    cin >> s;
    for (i = 0; i < 26; i++) {
        alpha[i] = 'a' + i;
        count[i] = -1;
    }

    for (i = 0; i < s.length(); i++)
        if (count[s.at(i) - 'a'] < 0) count[s.at(i) - 'a'] = i;
    for (i = 0; i < 26; i++) cout << count[i] << " ";
    cout << '\n';
}

int main() { solve(); }