/*
TASK: Sum the Series
1/3 + 2/21 + 3/91 + 4/273 + .....
(n^2-n+1)*(n^2+n+1)
Input:
5
1
2
3
4
5

Output:
0.33333
0.42857
0.46154
0.47619
0.48387
*/
#include <stdio.h>
int main()
{
int tN;
scanf("%d",&tN);
int* n=new int[tN];
for(int i=0;i<tN;i++)
scanf("%d",&n[i]);
for(int i=0;i<tN;i++)
printf("%.5lf\n",0.5-0.5/(n[i]*n[i]+n[i]+1));
delete n;
}
