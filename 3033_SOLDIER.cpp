//
//  3033_SOLDIER.cpp
//  
//
//  Created by Haijun Deng on 13-5-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Help the soldier
 ALGO: dynamic programming
 Input:
 7 53
 5 8 2
 2 4 8
 6 8 13
 1 13 12
 4 5 1
 3 2 7
 3 13 5
 
 Output:
 1
 */

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;

int dp[7][1001];
vector< pii > G[7];

int solve(int item, int money) 
{
	if(money < 0) 
        return 0;
	if(item > 6) 
        return 0x3f3f3f3f;
	if(dp[item][money]!=-1) 
        return dp[item][money];
	int& ret = dp[item][money];
	ret = 0;
	for(unsigned i = 0; i < G[item].size(); i++)
		if(money >= G[item][i].first)
			ret = max(ret, min(G[item][i].second, solve(item+1, money - G[item][i].first)));
	return ret;
}

int main() 
{
	int n, t, i, p, q, r;
	scanf("%d%d", &n, &t);
	memset(dp, -1, sizeof dp);
	for(i = 0; i < n; i++) 
    {
		scanf("%d %d %d", &p, &q, &r);
		G[p].push_back(pii(q, r));
	}
	printf("%d\n", solve(1, t));
	return 0;
}