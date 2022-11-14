#include <iostream>
#include <string>
using namespace std;

void solve() {
  string s;
  uint32_t r = 0;
  bool flag;
  getline(cin, s);

  if (s.at(0) == ' ')
    flag = false;  
  else
    flag = true;

  if(s.length() == 1) {
      cout << flag << '\n';
      return;
  }

  for (int i = 1; i < s.length()-1; i++) {
    if (s.at(i) == ' ' && flag){ 
      r++;
      flag = false;
    } else if (s.at(i) != ' ' && !flag)
      flag = true;
  }
    cout << ++r << '\n';
  
}

int main() { solve(); } 