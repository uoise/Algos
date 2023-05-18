#include<cstdio>
int n,r;char l,p[101];int main(){scanf("%d",&n);for(int i=0;i<n;i++){scanf("%s",p);if(!i)l=p[0];else if(!r)r=l!=p[0]?1:0;}printf("%d",r?0:1);}