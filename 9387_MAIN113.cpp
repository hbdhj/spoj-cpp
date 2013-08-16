/*
TASK: Special String
ALGO: dynamic programming
*/

#include <cstdio>

long long res[32];

int main() 
{
	res[1] = 3, res[2] = 9;
	for(int i = 3; i <= 30; i++) 
    {
		res[i] = res[i-1]*2 + res[i-2];
	}
	int test, n;
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%d", &n);
		printf("%lld\n", res[n]);
	}
	return 0;
}