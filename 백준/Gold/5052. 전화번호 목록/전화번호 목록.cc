#include <iostream>
char inp[11];
bool flag;
struct Trii {
    Trii* node[10];
    bool here;
    Trii(bool here = false) : here(here) {
        int i = 0;
        while (i++ < 10) node[i] = NULL;
    }
    void insert(int idx = 0) {
        if (idx == 11) return;
        if (here) flag = false;
        if (!(inp[idx] >= '0' && inp[idx] <= '9')) {
            int i = 0;
            while (i++ < 10)
                if (node[i] != NULL) flag = false;
            here = true;
            return;
        }
        int cur = inp[idx] - '0';
        if (node[cur] == NULL) node[cur] = new Trii();
        node[cur]->insert(idx + 1);
    }
};

void solve() {
    int N;
    Trii* tr = new Trii();
    flag = true;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", inp);
        tr->insert();
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
}