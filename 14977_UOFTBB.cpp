/*
TASK: Attack of the Bloons
Input:
1
10 3
3 3 1
4 0 4
10 2 2
4
1
20
9
11

Output:
1
Bloon leakage
5
8
*/

#include <stdio.h>

#include <vector>
#include <iostream>
#include <algorithm> 

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int L, N;
		scanf("%d %d", &L, &N);
		vector<int> Ci(N,0), Ri(N,0),Di(N,0);
		for(int i=0;i<N;i++)
		{
			scanf("%d %d %d", &Ci[i], &Ri[i], &Di[i]);
		}
		vector<int> Pi(L, 0);
		for(int i=0;i<N;i++)
		{
			//printf("Ci[%d] = %d, Ri[%d] = %d, Di[%d] = %d\n", i, Ci[i], i, Ri[i], i, Di[i]);
			//printf("start = %d, end = %d\n", Ci[i]-Ri[i]-1, Ci[i]+Ri[i]+1);
			int start = 0<(Ci[i]-Ri[i]-1)?(Ci[i]-Ri[i]-1):0;
			int end   = L>(Ci[i]+Ri[i])?(Ci[i]+Ri[i]):L;
			//printf("start = %d, end = %d\n", start, end);
			for(int j=start; j<end; j++)
			{
				Pi[j]+=Di[i];
			}
		}

		/*
		for(int i=0;i<L;i++)
		{
			printf("%d ", Pi[i]);
		}
		printf("\n");
		*/
		
		int M;
		scanf("%d", &M);
		while(M--)
		{
			int Hi;
			scanf("%d", &Hi);
			int cur=0;
			while(Hi>Pi[cur])
			{
				Hi-=Pi[cur];	
				cur++;
				if(cur>=L)
					break;
			}
			if(cur>=L)
				printf("Bloon leakage\n");
			else
				printf("%d\n", cur+1);
		}
		
	}
	return 0;
}
