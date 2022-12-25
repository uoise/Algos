#include <cstdio>
#include <queue>

struct Acs {
  Acs *rht[26];
  Acs *lft;
  bool ret;
  Acs() {
    for (auto &p : rht) p = nullptr;
    lft = nullptr;
    ret = 0;
  }
  void add(const char *s) {
    if (*s == '\0') {
      ret = 1;
    } else {
      int idx = *s - 'a';
      if (rht[idx] == nullptr) rht[idx] = new Acs;
      rht[idx]->add(s + 1);
    }
  }
};

int n;
char d[101], x[10001];
Acs *root = new Acs;
void init() {
  std::queue<Acs *> q;
  root->lft = root;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", d);
    root->add(d);
  }

  q.push(root);
  while (!q.empty()) {
    Acs *cur = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      Acs *nxt = cur->rht[i];
      if (nxt == nullptr) continue;
      if (cur == root) {
        nxt->lft = root;
      } else {
        Acs *tmp = cur->lft;
        while ((tmp != root) && (tmp->rht[i] == nullptr)) tmp = tmp->lft;
        if (tmp->rht[i] != nullptr) tmp = tmp->rht[i];
        nxt->lft = tmp;
        if (nxt->lft->ret) nxt->ret = 1;
      }
      q.push(nxt);
    }
  }
}

void sol() {
  scanf("%d", &n);
  while (n--) {
    scanf("%s", x);
    bool res = 0;
    Acs *cur = root;
    for (const auto &c : x) {
      if (c == '\0') break;
      int idx = c - 'a';
      while ((cur != root) && (cur->rht[idx] == nullptr)) cur = cur->lft;
      if (cur->rht[idx] != nullptr) cur = cur->rht[idx];
      if (cur->ret) {
        res = 1;
        break;
      }
    }
    printf("%s\n", (res ? "YES" : "NO"));
  }
}

int main() {
  init();
  sol();
}