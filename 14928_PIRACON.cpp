/*
 TASK: Pyramidal Constructions
 Input:
 2
 1
 4
 
 Output:
 Pyramid E. Nro# 1: 1
 Tringus: 0
 Pyramid E. Nro# 2: 68
 Tringus: 24

*/
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000
unsigned long long f[MAX];
unsigned long long e[MAX];

void p()
{
f[0]=1;
e[0]=0;
for (int i=1; i<MAX; i++) 
{
f[i]=(i+1)*(i+1)+i*i+f[i-1];
e[i]=(i)*4+e[i-1];
}
};

int main()
{
int t,i,j;
scanf("%d",&t);
p();
for (i=0; i<t; i++) {
scanf("%d",&j);
printf("Pyramid E. Nro# %d: %llu\nTringus: %llu\n", i+1, f[j-1]+e[j-1], e[j-1]);
}
return 0;
}