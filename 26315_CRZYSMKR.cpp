/*
TASK: CRZYSMKR - Crazy Smoker
ALGO: math
Input:
Input:
2
1
2

Output:
3
6
*/

#include <stdio.h>

using namespace std;

int main()
{
    int tN, i;
	unsigned long long int n;
	scanf("%d", &tN);
	for(i=0;i<tN;i++)
    {
        scanf("%llu",&n);
		printf("%llu\n", (11-((n%11)*8)%11)%11);
    }

	return 0;
}