#include <algorithm>
#include <cstdio>

struct Trie {
  Trie* child[2];
  void add(char* s) {
    if (!*s) return;
    int a = *s - '0';
    if (child[a] == nullptr) child[a] = new Trie();
    child[a]->add(s + 1);
  }

  void qry(char* s) {
    if (!*s) return;
    int a = (*s - '0') ^ 1;  // find xor max
    bool e = child[a] == nullptr;
    *s = e ? '0' : '1';
    child[a ^ e]->qry(s + 1);
  }
};

Trie root;
char s[33];
int n, v[100001], r;
void its(int c) {
  for (int i = 31; i >= 0; i--, c >>= 1) s[i] = (c & 1) ? '1' : '0';
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    its(v[i]);
    root.add(s);
  }

  for (int i = 0; i < n; i++) {
    its(v[i]);
    root.qry(s);
    int c = 0, b = 1;
    for (int j = 31; j >= 0; j--, b <<= 1) c |= (b * (s[j] == '1'));
    r = std::max(r, c);
  }

  printf("%d", r);
}