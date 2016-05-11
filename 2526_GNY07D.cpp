//
//  2526_GNY07D.cpp
//
//
//  Created by Haijun Deng on 13-4-15.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Decoding
 ALGO: simulation
 Input:
 4
 4 4 0000110100101100
 5 2 0110000010
 2 6 010000001001
 5 5 0100001000011010110000010

 Output:
 1 ACM
 2 HI
 3 HI
 4 HI HO
 */

#include <cstdio>
using namespace std;

char en[1024];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int R, C;

#define idx(r,c) (r*C+c)

int main()
{
	int t, i, x = 1, sr, sc, tot, dir;
	char ch;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%d%d%s", &R, &C, en);
		printf("%d ", x++);
		sr = sc = dir = 0;
		tot = R * C;
		for(ch = 0, i = 1; i <= tot; i++)
        {
			ch = (ch << 1)|(en[idx(sr,sc)]=='1');
			en[idx(sr,sc)] = 'X';
			if(i % 5 == 0)
            {
				ch = (!ch? ' ' : ch + 'A' - 1);
				putchar(ch);
				ch = 0;
			}
			sr += dr[dir], sc += dc[dir];
			if(sr<0 || sr>=R || sc<0 || sc>=C || en[idx(sr,sc)]=='X')
            {
				if(i < tot)
                {
					sr -= dr[dir], sc -= dc[dir];
					dir = (dir + 1) & 3;
					sr += dr[dir], sc += dc[dir];
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
