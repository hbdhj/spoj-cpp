/*
TASK: The Super Mario Blues
Input:
4
6-1
8-3
1-1
4-1


Output:
12
2
8 
6

TRAP 1-2, 4-2
*/

#include <stdio.h>

#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int w, l;
		scanf("%d-%d", &w, &l);
		if((w==1)&&(l<=2))
		{
			printf("%d\n",9-l);
		}
		else if((w<4)||(w==4)&&(l<=2))
		{
			printf("%d\n",(8-w)*4+4-l+1-14);
		}
		else
			printf("%d\n",(8-w)*4+4-l+1);
	}
	return 0;
}
