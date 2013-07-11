/*
TASK: Piggy-Bank
ALGO: dynamic programming
Sample Input:
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
Sample output:
The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int E, F, t, T, n, i, j, a[10001], v, w, INF=1<<28;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &E, &F);
		T = F-E;
		fill(&a[1], &a[1]+T, INF);
		a[0] = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &v, &w);
			printf("v = %d, w = %d, T = %d\n",v,w,T);
			for(j=0; j+w<=T; j++)
				if(a[j]!=INF && a[j+w] > a[j]+v)
				{
					a[j+w] = a[j] + v;
					printf("a[%d] = %d, a[%d] = %d\n",j+w,a[j+w],j,a[j]);
				}
		}
		if(a[T]!=INF) 
			printf("The minimum amount of money in the piggy-bank is %d.\n", a[T]);
		else 
			printf("This is impossible.\n");
	}
	return 0;
}
