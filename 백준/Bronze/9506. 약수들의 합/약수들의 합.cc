#include <cstdio>
#include <vector>

std::vector<int> v;
int n, s;
int main(){
  while(1){
    scanf("%d", &n);
    if(n == -1) break;
    s = 0;
    for(int i = 1; i < n && s <= n; i++) {
      if(n % i == 0) { 
        v.push_back(i);
        s += i;
      }
    }
    if(s != n) printf("%d is NOT perfect.", n);
    else {
      printf("%d = %d", n, v[0]);
      for(const int& i : v) if(i != v[0]) printf(" + %d", i);
    }
    printf("\n");
    v.clear();
  }
}