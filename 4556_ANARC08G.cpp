//
//  4556_ANARC08G.cpp
//  
//
//  Created by Haijun Deng on 13-4-14.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Think I will Buy Me a Football Team
 Input:
4
  0  50 100   0
150   0  20   0
  0   0   0  30
 30   0   0   0
0

Output:
1. 380 120
 */
#include <iostream>

int mat[1000][1000];
int rsum[1000], csum[1000];

int main() 
{
	int n, i, j, sum, diff, cs = 1;
	while(scanf("%d", &n)==1 && n) 
    {
		for(i = sum = 0; i < n; i++) 
        {
			for(j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
				sum += mat[i][j];
			}
		}
		for(i = 0; i < n; i++)
        {
			for(rsum[i] = csum[i] = j = 0; j < n; j++)
            {
				rsum[i] += mat[i][j];
				csum[i] += mat[j][i];
			}
		}
		for(i = diff = 0; i < n; i++)
			if(rsum[i] > csum[i])
				diff += rsum[i] - csum[i];
		printf("%d. %d %d\n", cs++, sum, diff);
	}
	return 0;
}
