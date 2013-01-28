#include <stdio.h>
#include <math.h>
int main()
{int i,t,m;scanf("%d",&t);int* n=new int[t];
for(i=0;i<t;i++)scanf("%d",&n[i]);
for(i=0;i<t;i++){m=n[i];float l=(m+sqrt(float(4+5*m*m)))/2;float k=(l*m+1)/(l-m);printf("%d\n",int(k+l));}
delete n;}
