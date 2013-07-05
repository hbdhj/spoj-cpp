//
//  243_STABLEMP.cpp
//  
//
//  Created by Haijun Deng on 13-4-9.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: stable marriage
 http://en.wikipedia.org/wiki/Stable_marriage_problem
 Input:
 2
 4
 1 4 3 1 2
 2 2 1 3 4
 3 1 3 4 2
 4 4 3 1 2
 1 3 2 4 1
 2 2 3 1 4
 3 3 1 2 4
 4 3 2 4 1
 7
 1 3 4 2 1 6 7 5
 2 6 4 2 3 5 1 7
 3 6 3 5 7 2 4 1
 4 1 6 3 2 4 7 5
 5 1 6 5 3 4 7 2
 6 1 7 3 4 5 6 2
 7 5 6 2 4 3 7 1
 1 4 5 3 7 2 6 1
 2 5 6 4 7 3 2 1
 3 1 6 5 4 3 7 2
 4 3 5 6 7 2 4 1
 5 1 7 6 4 3 5 2
 6 6 3 7 5 2 4 1
 7 1 7 4 2 6 5 3
 
 
 
 Output:
 1 3
 2 2
 3 1
 4 4
 1 4
 2 5
 3 1
 4 3
 5 7
 6 6
 7 2
 */
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 555;
int n, L[MAX][MAX], R[MAX][MAX], L2R[MAX], R2L[MAX], p[MAX];

void stable() 
{
	memset(R2L, -1, sizeof R2L);
	memset(p, 0, sizeof p);
	for(int i = 0; i < n; i++)
    {
		int girl = i;
		while(girl >= 0)
        {
			int boy;
			while(true) 
            {
				boy = L[girl][p[girl]++];
				if(R2L[boy] < 0 || R[boy][girl] > R[boy][R2L[boy]]) 
                    break;
			}
			int match = R2L[boy];
			R2L[L2R[girl] = boy] = girl;
			girl = match;
		}
	}
}

int main() 
{
	int t, part, wom, man;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) 
        {
			scanf("%d", &man);
			man--;
			for(int j = 0; j < n; j++) 
            {
				scanf("%d", &part);
				part--;
				R[man][part] = n - j;
			}
		}
		for(int i = 0; i < n; i++) 
        {
			scanf("%d", &wom);
			wom--;
			for(int j = 0; j < n; j++) 
            {
				scanf("%d", &part);
				part--;
				L[wom][j] = part;
			}
		}
        
		stable();
		for(int i = 0; i < n; i++) 
            printf("%d %d\n", i + 1, L2R[i] + 1);
	}
	return 0;
}
