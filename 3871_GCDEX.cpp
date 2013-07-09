/*
TASK: GCDEX
ALGO: math, euler phi
*/


#include <cstdio>

#define MAX 1000001

long long g[MAX];
int phi[MAX];

int main()
{
	int i, j, n;

	for(i=2,phi[1]=1; i<MAX; i++)
	{
		if(!phi[i])
		{
			phi[i] = i-1;
			for(j=(i<<1); j<MAX; j+=i)
			{
				if(!phi[j]) 
                    phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}

	for(i=1; i<MAX; i++)
		for(j=2; i*j<MAX; j++)
			g[i*j] += i*phi[j];

	for(i=2; i<MAX; i++)
		g[i] += g[i-1];

	while(scanf("%d", &n)==1 && n)
		printf("%lld\n", g[n]);

	return 0;
}
