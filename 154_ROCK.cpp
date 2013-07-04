//
//  154_ROCK.cpp
//  
//
//  Created by Haijun Deng on 13-3-16.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Sweet and Sour Rock
 Sample input:
2
15
100110001010001
16
0010111101100000

Sample output:
9
13

 */
#include <iostream>
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
int main() 
{
	int t, n, i, j, add, cnt;
	int memo[256];
	char rock[256];
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d%s", &n, rock);
		memo[0] = rock[0]-'0';
		for(i = 1; i < n; i++) 
        {
			memo[i] = memo[i-1];
			cnt = 0;
			for(j = i; j >= 0; j--) 
            {
				cnt += ((rock[j]=='1')? 1 : -1);
				if(cnt > 0) 
                {
					add = i - j + 1;
					if(j > 0) 
                        add += memo[j-1];
					setmax(memo[i], add);
				}
			}
		}
		printf("%d\n", memo[n-1]);
	}
	return 0;
}
