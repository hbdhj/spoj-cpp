//
//  4177_HERDING.cpp
//
//
//  Created by Haijun Deng on 13-5-5.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 ALGO: flood fill
 Input:
 3 4
 SWWW
 SEWN
 EEEN

 Output:
 2
 */

#include <cstdio>
using namespace std;

#define MAX 1000

char grid[MAX][MAX+1];
int R, C, trap[MAX][MAX], count, last;

void floodfill(int i, int j)
{
	if(i>=0 && j>=0 && i<R && j<C)
	{
		if(trap[i][j])
		{
			count = trap[i][j];
			return;
		}
		trap[i][j] = count;
		if(grid[i][j]=='W')
            floodfill(i, j-1);
		else if(grid[i][j]=='E')
            floodfill(i, j+1);
		else if(grid[i][j]=='N')
            floodfill(i-1, j);
		else if(grid[i][j]=='S')
            floodfill(i+1, j);
		trap[i][j] = count;
	}
}

int main()
{
	scanf("%d%d", &R, &C);
	for(int i=0; i<R; i++) scanf("%s", grid[i]);
	for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(!trap[i][j])
            {
                count = last + 1;
                floodfill(i, j);
                if(count > last)
                    last++;
            }
	printf("%d\n", last);
	return 0;
}
