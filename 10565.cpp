/*
10565. Alice Sieve
Input:
3
2
3
5
Output:
1
2
3
*/
#include <stdio.h>
int main()
{
	int t,n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n%2)
			printf("%d\n",(n+1)/2);
		else
			printf("%d\n",n/2);
	}
	return 0;
}