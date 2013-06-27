/*
TASK: PERMUT1
ALGO: dynamic programming
 Sample input:
 1 
 4 1 
 
 Sample output:
 3 
*/

#include <cstdio>
using namespace std;

int cnt[16][128];

void calc() 
{
	int i, j, k;
	cnt[1][0] = 1;
	for(i=1; i<12; i++) 
    {
		for(j=0; cnt[i][j]; j++)
        {
			for(k=j; k<=i+j; k++) 
            {
				cnt[i+1][k] += cnt[i][j];
			}
		}
	}
}

int main() 
{
	int t, n, k;
	calc();
    /*for (int i = 0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            printf("%d ", cnt[i][j]);
        }
        printf("\n");
    }*/
	for(scanf("%d", &t); t; t--) 
    {
		scanf("%d%d", &n, &k);
		printf("%d\n", cnt[n][k]);
	}
	return 0;
}
