//
//  3411_SAMER08G.cpp
//
//
//  Created by Haijun Deng on 13-4-11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Pole Position
 ALGO: ad-hoc
 Input:
 4
 1 0
 3 1
 2 -1
 4 0
 4
 22 1
 9 1
 13 0
 21 -2
 3
 19 1
 9 -345
 17 0
 7
 2 2
 8 0
 5 -2
 7 1
 1 1
 9 1
 3 -3
 0


 Output:
 1 2 3 4
 -1
 -1
 5 8 2 3 7 1 9
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1000;
int car[MAX], pos[MAX], cng[MAX];

int main()
{
	int n, i, sp;
	while(scanf("%d", &n)==1 && n)
    {
		for(i = 0; i < n; i++)
            scanf("%d%d", &car[i], &cng[i]);
		memset(pos, -1, sizeof pos);
		for(i = 0; i < n; i++)
        {
			sp = i + cng[i];
			if(sp >= 0 && sp < n && pos[sp]==-1)
                pos[sp] = car[i];
			else
                break;
		}
		if(i == n)
        {
			printf("%d", pos[0]);
			for(i = 1; i < n; i++)
                printf(" %d", pos[i]);
			printf("\n");
		}
		else
            printf("-1\n");
	}
	return 0;
}
