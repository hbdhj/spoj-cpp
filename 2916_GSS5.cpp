//
//  2916_GSS5.cpp
//
//
//  Created by Haijun Deng on 13-5-31.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Can you answer these queries V
 ALGO: segment tree
 Input:
 2
 6 3 -2 1 -4 5 2
 2
 1 1 2 3
 1 3 2 5
 1 1
 1
 1 1 1 1

 Output:
 2
 3
 1
 */
#include <iostream>
using namespace std;

template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }

const int MAX = 1 << 14;

typedef struct { int sum, suf, pre, max; } Node;

int a[MAX];
Node T[MAX << 1];

void init(int x, int i, int j)
{
	if(i == j)
    {
		T[x].sum = T[x].pre = T[x].suf = T[x].max = a[i];
		return;
	}
	int m = (i + j) >> 1, lt = x << 1, rt = lt | 1;
	init(lt, i, m);
	init(rt, m+1, j);
	T[x].sum = T[lt].sum + T[rt].sum;
	T[x].pre = _max(T[lt].pre, T[lt].sum + T[rt].pre);
	T[x].suf = _max(T[lt].suf + T[rt].sum, T[rt].suf);
	T[x].max = _max(T[lt].suf + T[rt].pre, _max(T[lt].max, T[rt].max));
}

Node query(int x, int i, int j, int p, int q)
{
	if(p > q)
        return T[0];
	if(i == p && j == q)
        return T[x];
	int m = (i + j) >> 1, lt = x << 1, rt = lt | 1;
	if(q <= m)
        return query(lt, i, m, p, q);
	else if(p > m)
        return query(rt, m+1, j, p, q);
	else
    {
		Node retl, retr, ret;
		retl = query(lt, i, m, p, m);
		retr = query(rt, m+1, j, m+1, q);
		ret.sum = retl.sum + retr.sum;
		ret.pre = _max(retl.pre, retl.sum + retr.pre);
		ret.suf = _max(retl.suf + retr.sum, retr.suf);
		ret.max = _max(retl.suf + retr.pre, _max(retl.max, retr.max));
		return ret;
	}
}

int main()
{
	int test, cs, n, q, i, x1, y1, x2, y2, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++)
    {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
            scanf("%d", a + i);
		init(1, 0, n-1);
		scanf("%d", &q);
		while(q--)
        {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--, y1--, x2--, y2--;
			if(y1 < x2)
            {
				res = query(1, 0, n-1, x1, y1).suf;
				res += query(1, 0, n-1, y1+1, x2-1).sum;
				res += query(1, 0, n-1, x2, y2).pre;
			}
			else
            {
				res = query(1, 0, n-1, x2, y1).max;
				res = _max(res, _max(
                                     query(1, 0, n-1, x1, x2-1).suf + query(1, 0, n-1, x2, y2).pre,
                                     query(1, 0, n-1, x1, y1).suf + query(1, 0, n-1, y1+1, y2).pre
                                     ));
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
