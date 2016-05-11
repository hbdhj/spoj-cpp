//
//  733_MTWALK.cpp
//
//
//  Created by Haijun Deng on 13-4-21.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: breadth first search
 Input:
 5
 1 1 3 6 8
 1 2 2 5 5
 4 4 0 3 3
 8 0 2 3 4
 4 3 0 2 1

 Output:
 2
 */
#include <iostream>
#include <queue>
using namespace std;

template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MEM(p, v) memset(p, v, sizeof(p))

const int MAX = 128;
const int INF = 0x3f3f3f3f;

int d[MAX][MAX][MAX], grid[MAX][MAX], n;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs()
{
	int r1, c1, r2, c2, h1, h2, w1, w2, i;
	queue< int > Q;
	Q.push(0), Q.push(0), Q.push(grid[0][0]);
	d[0][0][grid[0][0]] = 0;
	while(!Q.empty())
    {
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		h1 = Q.front(); Q.pop();
		w1 = d[r1][c1][h1];
		for(i = 0; i < 4; i++)
        {
			r2 = r1 + dr[i];
			c2 = c1 + dc[i];
			if(inside(0, r2, n-1) && inside(0, c2, n-1))
            {
				if(h1 > grid[r2][c2])
                    h2 = grid[r2][c2], w2 = w1 + h1 - h2;
				else
                    h2 = h1, w2 = max(w1, grid[r2][c2] - h1);
				if(d[r2][c2][h2] > w2)
                {
					d[r2][c2][h2] = w2;
					if(r2==n-1 && c2==n-1) continue;
					Q.push(r2), Q.push(c2), Q.push(h2);
				}
			}
		}
	}
	for(i = 0, w1 = INF; i < MAX; i++)
        setmin(w1, d[n-1][n-1][i]);
	return w1;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	MEM(d, 0x3f);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
	printf("%d\n", bfs());
	return 0;
}
