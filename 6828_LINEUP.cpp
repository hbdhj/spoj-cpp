/*
6828. Lineup
Input:
1
100 0 0 0 0 0 0 0 0 0 0
0 80 70 70 60 0 0 0 0 0 0
0 40 90 90 40 0 0 0 0 0 0
0 40 85 85 33 0 0 0 0 0 0
0 70 60 60 85 0 0 0 0 0 0
0 0 0 0 0 95 70 60 60 0 0
0 45 0 0 0 80 90 50 70 0 0
0 0 0 0 0 40 90 90 40 70 0
0 0 0 0 0 0 50 70 85 50 0
0 0 0 0 0 0 66 60 0 80 80
0 0 0 0 0 0 50 50 0 90 88

Output:
970
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[11][1<<11], pl[11][11];

int solve(int pos, int mask) 
{
	if(pos == 11) {
		if(mask != (1<<11)-1) 
            return -INF;
		else 
            return 0;
	}
	if(dp[pos][mask] > -1) 
        return dp[pos][mask];
	int &ret = dp[pos][mask]; 
    ret = -INF;
	for(int i = 0, temp; i < 11; i++) 
    {
		if(pl[i][pos] && !(mask&(1<<i))) 
        {
			temp = pl[i][pos] + solve(pos + 1, mask | (1 << i));
			ret = max(ret, temp);
		}
	}
	return ret;
}

int main() {
	int test, i, j;
	scanf("%d", &test);
	while(test--) 
    {
		for(i = 0; i < 11; i++)
			for(j = 0; j < 11; j++)
				scanf("%d", &pl[i][j]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(0, 0));
	}
	return 0;
}