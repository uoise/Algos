#include <cstdio>
#include <list>

char s[1000001];
void sol() {
  scanf("%s", s);
  std::list<char> l;
  auto p = l.begin();
  for (int i = 0; s[i] != '\0'; i++) {
    switch (s[i]) {
      case '<':
        if (p != l.begin()) --p;
        break;
      case '>':
        if (p != l.end()) ++p;
        break;
      case '-':
        if (p != l.begin()) p = l.erase(--p);
        break;
      default:
        l.insert(p, s[i]);
    }
  }
  for (const char& c : l) printf("%c", c);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}