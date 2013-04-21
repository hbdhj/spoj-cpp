//
//  8002_HORRIBLE.cpp
//  
//
//  Created by Haijun Deng on 13-4-21.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: segment tree
 Input:
 1
 8 6
 0 2 4 26
 0 4 8 80
 0 4 5 20
 1 8 8 
 0 5 7 14
 1 4 8
 
 Output:
 80
 508
 */
#include <iostream>
const int MAX = 1 << 18;
long long Tree[MAX][2]; // 0 sum, 1 add

void update(int Node, int i, int j, int x, int y, int v) 
{
	if(i == x && j == y) 
    {
		Tree[Node][1] += v;
		Tree[Node][0] += (long long)v * (y-x+1);
		return;
	}
	int m, l, r;
	m = (i + j) >> 1; 
    l = Node << 1; 
    r = l + 1;
	if(y <= m) 
        update(l, i, m, x, y, v);
	else if(x > m) 
        update(r, m+1, j, x, y, v);
	else 
    {
		update(l, i, m, x, m, v);
		update(r, m+1, j, m+1, y, v);
	}
	Tree[Node][0] = Tree[l][0] + Tree[r][0] + Tree[Node][1] * (j-i+1);
}

long long query(int Node, int i, int j, int x, int y, long long v) 
{
	if(i == x && j == y) 
        return Tree[Node][0] + v * (y-x+1);
	int m, l, r;
	m = (i + j) >> 1; 
    l = Node << 1; 
    r = l + 1;
	if(y <= m) 
        return query(l, i, m, x, y, v + Tree[Node][1]);
	else if(x > m) 
        return query(r, m+1, j, x, y, v + Tree[Node][1]);
	else 
    {
		long long ret = 0;
		ret += query(l, i, m, x, m, v + Tree[Node][1]);
		ret += query(r, m+1, j, m+1, y, v + Tree[Node][1]);
		return ret;
	}
}

int main() 
{
	int test, n, q, c, x, y, a;
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%d%d", &n, &q);
		memset(Tree, 0, sizeof(Tree));
		while(q--) 
        {
			scanf("%d%d%d", &c, &x, &y);
			if(c) 
                printf("%lld\n", query(1, 0, n-1, x-1, y-1, 0));
			else 
            {
				scanf("%d", &a);
				update(1, 0, n-1, x-1, y-1, a);
			}
		}
	}
	return 0;
}
