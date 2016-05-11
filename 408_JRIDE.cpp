//
//  408_JRIDE.cpp
//
//
//  Created by Haijun Deng on 13-5-12.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 ALGO: dynamic programming
 Input:
 3
 3
 -1
 6
 10
 4
 -5
 4
 -3
 4
 4
 -4
 4
 -5
 4
 -2
 -3
 -4

 Output:

 The nicest part of route 1 is between stops 2 and 3
 The nicest part of route 2 is between stops 3 and 9
 Route 3 has no nice parts
 */

#include <cstdio>
using namespace std;

const int MAX = 100032;
int in[MAX];

int main()
{
	int i, te, tc = 1, n, ts, td, tmp, s, d, ans;
	scanf("%d",&te);
	while(te--)
    {
		scanf("%d",&n); n--;
		for(i = 0; i < n; i++)
            scanf("%d",&in[i]);
		ts = 0, td, tmp = 0, ans = -1, s = -1, d = -1;
		for(i = 0; i < n; i++)
        {
			td = i;
			if(tmp+in[i] > ans)
            {
				ans = tmp+in[i];
				s = ts;
				d = td;
			}
			else if(tmp+in[i] == ans && td-ts > d-s)
            {
				s=ts;
				d=td;
			}
			if(tmp+in[i] >= 0)
                tmp+=in[i];
			else if(tmp+in[i] < 0)
            {
				tmp = 0;
				ts = i+1;
			}
		}
		if(s != -1)
            printf("The nicest part of route %d is between stops %d and %d\n", tc++, s+1, d+2);
		else
            printf("Route %d has no nice parts\n",tc++);
	}
	return 0;
}
