/*
TASK: Vertex Cover
ALGO: bipartite matching
 Example 1

 Input:
 3
 1 2
 1 3
 
 Output:
 1
 
 Explanation:
 The set can be {1}
 
 Example 2
 
 Input:
 3
 1 2
 2 3
 
 Output:
 1
 
 Explanation:
 The set can be {2}
*/

#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))

const int MAX = 100001;

vector< int > edges[MAX];
bool visited[MAX], color[MAX];
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

int match(int n) 
{
    SET(Left);
    SET(Right);
    int i, ret = 0;
    bool done;
    do 
    {
        done = true;
        CLR(visited);
        for(i=1; i<=n; i++) 
        {
            if(color[i] && Left[i]==-1 && dfs(i)) 
            {
                done = false;
            }
        }
    } while(!done);
    for(i=1; i<=n; i++)
    {
		if(color[i])
        {
			ret += (Left[i]!=-1);
        }
    }
    return ret;
}

void colorVertices(int u, int d) 
{
	if(visited[u]) 
        return;
	visited[u] = true;
	color[u] = (d&1);
	int i, v, len = edges[u].size();
	for(i=0; i<len; i++) 
    {
		v = edges[u][i];
		colorVertices(v, d+1);
	}
}

int main() 
{
	int n, i, u, v;
	scanf("%d", &n);
	for(i=1; i<n; i++) 
    {
		scanf("%d%d", &u, &v);
		edges[u].push_back(v); 
        edges[v].push_back(u);
	}
	colorVertices(1, 0);
	printf("%d\n", match(n));
	return 0;
}
