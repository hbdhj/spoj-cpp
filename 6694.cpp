/*
6694. D - Playing with Marbles
Sample Input
1
2
3
0
Sample Output
5
12
22
*/
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n>0)
	{
		int ret=0;
		for(int i=(n+1);i<2*(n+1);i++)
			ret+=i;
		printf("%d\n", ret);
		scanf("%d",&n);
	}
	return 0;
}