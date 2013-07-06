//
//  277_CTGAME.cpp
//  
//
//  Created by Haijun Deng on 13-4-13.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: City Game
Input:
2
5 6
R F F F F F
F F F F F F
R R R F F F
F F F F F F
F F F F F F

5 5
R R R R R
R R R R R
R R R R R
R R R R R
R R R R R

Output:
45
0
*/

#include <iostream>

template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }

const int MAX = 1009;

int calc(int *ht, int n) 
{
	int ret = 0, top = 1, st[MAX], i;
	ht[0] = st[0] = ht[++n] = 0;
	for(i = 1; i <= n; i++) 
    {
		while(top > 1 && ht[st[top-1]] >= ht[i]) 
        {
			ret = _max(ret, ht[st[top-1]]*(i - st[top-2]-1));
			top--;
		}
		st[top++] = i;
	}
	return ret;
}

int main() 
{
	int test, i, j, k, ret, R, C, row[2][MAX];
	char str[2048];
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%d %d", &R, &C);
		fgets(str, 2048, stdin);
		memset(row[0], 0, sizeof(int)*(C+1));
		for(ret = 0, i = 1; i <= R; i++) 
        {
			fgets(str, 2048, stdin);
			for(j = 0, k = 1; str[j]; j++) 
            {
				if(str[j]=='F') 
                {
                    row[i&1][k] = 1 + row[(i-1)&1][k];
                    k++; 
                }
				else if(str[j]=='R') 
                    row[i&1][k++] = 0;
			}
			ret = _max(ret, calc(row[i&1], C));
		}
		printf("%d\n", 3*ret);
	}
	return 0;
}
