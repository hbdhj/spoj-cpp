//
//  660_QUEST4.CPP
//  
//
//  Created by Haijun Deng on 13-4-25.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))

const int MAX = 120;

vector < int > edges[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) 
{
	if(visited[u]) 
        return false;
	visited[u] = true;
	int len = edges[u].size(), i, v;
	for(i=0; i<len; i++) 
    {
		v = edges[u][i];
		if(Right[v]==-1) 
        {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) 
    {
		v = edges[u][i];
		if(dfs(Right[v])) 
        {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}

int match() {
	SET(Left);
	SET(Right);
	int i, ret = 0;
	bool done;
	do 
    {
		done = true;
		CLR(visited);
		for(i=0; i<MAX; i++) 
        {
			if(Left[i]==-1 && dfs(i)) 
            {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<MAX; i++) 
        ret += (Left[i]!=-1);
	return ret;
}

int main() {
	int t, n, i, x, y;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d", &n);
		for(i=0; i<MAX; i++) 
            edges[i].clear();
		for(i=0; i<n; i++) 
        {
			scanf("%d%d", &x, &y);
			edges[x].push_back(y);
		}
		printf("%d\n", match());
	}
	return 0;
}