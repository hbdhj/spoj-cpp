/* 
TASK: Foxling Feeding Frenzy
Input:
2
2 5
1 4
2 6
3 5
2 2
2 9
2 3

Output:
3
0
*/
#include <stdio.h>

#include <vector>
#include <iostream>

using namespace std;

unsigned long long Factorial(unsigned int n)
{
	if(n==1)
		return 1;
	else
		return n*Factorial(n-1);
}

int main()
{
	int T, N, M, i;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		vector<int> Ai(N, 0), Bi(N, 0);
		int Ai_Total = 0;
		for(i=0; i<N; i++)
		{
			scanf("%d %d", &Ai[i], &Bi[i]);
			Ai_Total += Ai[i];
		}
		if(Ai_Total>M)
			printf("0\n");
		else if(Ai_Total==M)
			printf("1\n");
		else
		{
			printf("%lld\n", Factorial(M-Ai_Total)+1);
		}
	}
	return 0;
}
