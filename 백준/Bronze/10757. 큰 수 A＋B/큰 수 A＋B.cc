#include <stdio.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    vector<int> ar1;
    vector<int> ar2;
    vector<int> ar3;
    vector<int>::iterator it;
    char r;
    char l = '0';
    int t;
    while (true) {
        scanf("%1c", &r);
        if (r < '0' || r > '9') break;
        ar1.push_back(r - l);
    }
    while (true) {
        scanf("%1c", &r);
        if (r < '0' || r > '9') break;
        ar2.push_back(r - l);
    }
    t = 0;
    while (!ar1.empty() || !ar2.empty()) {
        if (ar1.empty()) {
            if (t + ar2.back() >= 10) {
                ar3.push_back(t + ar2.back() - 10);
                t = 1;
            } else {
                ar3.push_back(t + ar2.back());
                t = 0;
            }
            ar2.pop_back();
        } else if (ar2.empty()) {
            if (t + ar1.back() >= 10) {
                ar3.push_back(t + ar1.back() - 10);
                t = 1;
            } else {
                ar3.push_back(t + ar1.back());
                t = 0;
            }
            ar1.pop_back();
        } else {
            if (t + ar1.back() + ar2.back() >= 10) {
                ar3.push_back(t + ar1.back() + ar2.back() - 10);
                t = 1;
            } else {
                ar3.push_back(t + ar1.back() + ar2.back());
                t = 0;
            }
            ar1.pop_back();
            ar2.pop_back();
        }
    }
    if(t==1) ar3.push_back(1);
    reverse(ar3.begin(), ar3.end());
    for (it = ar3.begin(); it != ar3.end(); it++) cout << *it;
    cout << endl;
}

int main() { solve(); }