#include <cstdio>
int r=-1,x,y,z;
int main(){
for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){scanf("%d",&z);if(r<z)r=z,y=i,x=j;}
printf("%d\n%d %d",r,y,x);
}