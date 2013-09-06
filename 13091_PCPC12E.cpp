/*
TASK: Snakes and Ladders
ALGO: bfs
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 1 << 14;
const int INF = 0x3f3f3f3f;

int G[MAX], d[MAX], last[MAX];
int curr, depth;

int check(int u) 
{
	depth++;
	if(last[u] == -1) {
		if(u == curr && depth > 1) 
            return INF;
		if(G[u] == -1) 
            last[u] = u;
		else 
            last[u] = check(G[u]);
	}
	return last[u];
}

int bfs(int st, int en) {
	int u, v, i;
	queue< int > Q;
	d[st] = 0;
	Q.push(st);
	while(!Q.empty()) 
    {
		u = Q.front();
        Q.pop();
		for(i = 1; i <= 6; i++) 
        {
			v = u + i;
			if(v > en)
                break;
			v = check(v);
			if(v < INF && d[v] == -1)
            {
				d[v] = d[u] + 1;
				if(v == en) 
                    return d[v];
				else 
                    Q.push(v);
			}
		}
	}
	return -1;
}

int main() 
{
	int n, m, s, l, i, u, v;
	//freopen("in.txt", "r", stdin);
	while(scanf("%d %d %d %d", &n, &m, &s, &l) == 4) 
    {
		memset(G, -1, sizeof G);
		memset(last, -1, sizeof last);
		memset(d, -1, sizeof d);
		for(i = 0; i < s; i++)
        {
			scanf("%d %d", &u, &v);
			G[u] = v;
		}
		for(i = 0; i < l; i++) 
        {
			scanf("%d %d", &u, &v);
			G[u] = v;
		}
		u = 0, v = n * m;
		for(i = u; i <= v; i++)
        {
			if(last[i] == -1)
            {
				curr = i, depth = 0;
				check(i);
			}
		}
		printf("%d\n", bfs(u, v));
	}
	return 0;
}