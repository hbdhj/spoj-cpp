//
//  63_SQRBR.cpp
//
//
//  Created by Haijun Deng on 13-4-5.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: dynamic programming
 Sample input:
 5
 1 1
 1
 1 1
 2
 2 1
 1
 3 1
 2
 4 2
 5 7

 Sample output:
 1
 0
 2
 3
 2

 */
#include <iostream>

const int MAX = 40;

bool f[MAX];
int dp[MAX][MAX], n;

long long solve(int pos, int open)
{
	if(open < 0)
        return 0; // invalid
	if(pos == n)
        return open == 0; // must for being valid
	int &ret = dp[pos][open];
	if(ret != -1)
        return ret;
	if(f[pos])
        return ret = solve(pos+1, open+1); // must put a [ here
	return ret = solve(pos+1, open+1) + solve(pos+1, open-1); // try [ and ] both
}

int main()
{
	int t, k, m, i;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%d%d", &n, &k);
		n <<= 1;
        memset(f, 0, sizeof(f));
		memset(dp, -1, sizeof(dp));
        for(i = 0; i < k; i++)
        {
			scanf("%d", &m);
			f[m-1] = 1;
		}
		printf("%lld\n", solve(0, 0));
	}
	return 0;
}
