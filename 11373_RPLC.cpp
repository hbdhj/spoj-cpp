/*
TASK: Coke madness
INPUT
2
5
4 -10 4 4 4
5
1 2 3 4 5
OUTPUT
Scenario #1: 7
Scenario #2: 1
*/

#include<stdio.h>
int main()
{
	int t, i = 1;
	long long int m, n, sum, ans;
	scanf("%d", &t);
	while(i <= t)
	{
		scanf("%lld", &n);
		ans = 0; sum = 0;
		while(n--)
		{
			scanf("%lld", &m);
			sum += m;
			if(sum < 0)	//reason we failed before
			{
				ans = ans - sum; 
				sum = 0;
			}
		}
		printf("Scenario #%d: %lld\n", i, ans + 1);
		i++;
	}
	return 0;
}
