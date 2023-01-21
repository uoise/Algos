#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
char s[1001];
vector<string> v;
int main() {
  scanf("%s", s);
  for (int i = 0; s[i] != '\0'; i++) v.push_back(s + i);
  sort(v.begin(), v.end());
  for (const auto& r : v) printf("%s\n", r.c_str());
}