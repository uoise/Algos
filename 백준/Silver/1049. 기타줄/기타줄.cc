#include<algorithm>
#include<cstdio>
int n,m,x,y,s=1e4,e=1e4,r;main(){scanf("%d%d",&n,&m);while(m--){scanf("%d%d",&x,&y);s=std::min(s,x),e=std::min(e,y);}r=std::min(n*e,n/6*s+n%6*e);if(n%6)r=std::min(r,(n/6+1)*s);printf("%d",r);}
