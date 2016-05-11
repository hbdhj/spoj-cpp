//
//  96_SHOP.cpp
//
//
//  Created by Haijun Deng on 13-5-18.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Highways
 ALGO: dijkstra
 Input:
 2
 4 2 1 4
 1 2 5
 3 4 5
 4 4 1 4
 1 2 5
 2 3 5
 3 4 5
 4 2 6


 Output:
 NONE
 11
 */

#include <cstdio>
#include <queue>
#include <cstring>
#include <cctype>

using namespace std;

#define MAX 100010
#define INF 2147483647

vector< pair<int, int> > G[MAX];
int d[MAX], f[MAX];

int process(int n, int e, int start, int end)
{
	int u, v, w, we, wn, size;

	for(int i=0;i<n+1;i++)
    {
		G[i].clear();
		d[i] = INF;
		f[i] = 0;
	}

	for(int i=0;i<e;i++)
    {
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(pair<int, int>(w,v));
		G[v].push_back(pair<int, int>(w,u));
	}

	d[start] = 0;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;
	Q.push(pair<int, int>(0, start));

	while(!Q.empty())
    {
		u = Q.top().second;
		wn = Q.top().first;
		Q.pop();
		size = G[u].size();
		for(int i=0; i<size;i++)
        {
			v = G[u][i].second;
			we = G[u][i].first;
			if(!f[v] && wn + we <= d[v])
            {
				d[v] = wn+we;
				Q.push(pair<int, int>(d[v], v));
			}
		}
		f[u] = 1;
		if(u==end)
            break;
	}

	return d[end];
}

int main()
{
	int t, n, e, start, end, dist;
	scanf("%d", &t);
	while(t--)
    {
		scanf("%d %d %d %d", &n, &e, &start, &end);
		dist = process(n, e, start, end);
		if(dist==INF)
            printf("NONE\n");
		else
            printf("%d\n", dist);
	}
	return 0;
}
