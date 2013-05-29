/*
TASK: Princess Farida
ALGO: dynamic programming
Input:
6
5
1 2 3 4 5
1
10
3 
2 4 3
0
9 
1 3 5 9 7 10 1 10 100 
4
4 3 2 1

Output:
Case 1: 9
Case 2: 10
Case 3: 5
Case 4: 0
Case 5: 122
Case 6: 6

*/
#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		long n;
		scanf("%ld", &n);
		vector<long long> monsters(n, 0);
		for(long j=0; j<n; j++)
		{
			scanf("%lld", &monsters[j]);
		}
		long long ret=0;
		if(n>3)
		{
			monsters[n-3]+=monsters[n-1];
			for(long j=n-4; j>=0; j--)
			{
				if(monsters[j+2]>monsters[j+3])
					monsters[j]+=monsters[j+2];
				else
					monsters[j]+=monsters[j+3];
			}
			/*for(int j=0; j<n; j++)
			{
				printf("%ld ", monsters[j]);
			}
			printf("\n");*/
			for(long j=0; j<2; j++)
			{
				if(ret<monsters[j])
					ret=monsters[j];
			}
		}
		else if(n)
		{
			for(long j=n-3; j>=0; j--)
			{
				monsters[j]+=monsters[j+2];
			}
			for(long j=0; j<(n>2?2:n); j++)
			{
				if(ret<monsters[j])
					ret=monsters[j];
			}
		}
		printf("Case %d: %lld\n", i+1, ret);
	}
	return 0;
}
