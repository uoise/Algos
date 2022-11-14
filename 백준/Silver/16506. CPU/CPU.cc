#include <iostream>
#include <vector>

using namespace std;

pair<string, string> ops[23] = {
    {"ADD", "00000"},    {"SUB", "00010"},    {"MOV", "00100"},
    {"AND", "00110"},    {"OR", "01000"},     {"NOT", "01010"},
    {"MULT", "01100"},   {"LSFTL", "01110"},  {"LSFTR", "10000"},
    {"ASFTR", "10010"},  {"RL", "10100"},     {"RR", "10110"},
    {"ADDC", "00001"},   {"SUBC", "00011"},   {"MOVC", "00101"},
    {"ANDC", "00111"},   {"ORC", "01001"},    {"MULTC", "01101"},
    {"LSFTLC", "01111"}, {"LSFTRC", "10001"}, {"ASFTRC", "10011"},
    {"RLC", "10101"},    {"RRC", "10111"}};

void clc(int x, int siz) {
  vector<bool> r;
  while (x) {
    r.push_back(x % 2);
    x /= 2;
  }
  while (r.size() != siz) r.push_back(0);
  for (int i = r.size() - 1; i >= 0; i--) cout << r[i];
}

void sol(string op, int rd, int ra, int rb) {
  for (int i = 0; i < 23; i++)
    if (op == ops[i].first) {
      cout << ops[i].second << '0';
      clc(rd, 3);
      clc(ra, 3);
      if (i < 12) {
        clc(rb, 3);
        cout << '0';
      } else
        clc(rb, 4);
      cout << '\n';
      return;
    }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int TC, rd, ra, rb;
  string op;
  cin >> TC;
  while (TC--) {
    cin >> op >> rd >> ra >> rb;
    sol(op, rd, ra, rb);
  }
}