#include <iostream>
#include <map>
using namespace std;
int inp;
string snp;

struct Trii{
    map<string, Trii*> node;
    int loc;
    Trii(int loc = 0) : loc(loc) {}
    void insert(int loc=0){
        if(loc == inp) return;
        cin >> snp;
        node.emplace(snp, new Trii(loc+1));
        node[snp]->insert(loc+1);
    }
    void print(){
        map<string, Trii*>::iterator it;
        for (it = node.begin(); it != node.end(); it++) {
            int i = 0;
            while(i++ < loc) cout << "--";
            cout << it->first << '\n';
            it->second->print();
        }
    }
};

void solve(){
    int N, i;
    Trii * tr = new Trii();
    cin >> N;
    for(i=0; i<N; i++){
        cin >> inp;
        tr->insert();
    }
    tr->print();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}