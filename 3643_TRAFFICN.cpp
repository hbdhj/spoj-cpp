/*
TASK: Traffic Network
ALGO: dijkstra
 Sample Input
 1
 4 5 3 1 4
 1 2 13
 2 3 19
 3 1 25
 3 4 17
 4 1 18
 1 3 23
 2 3 5
 2 4 25	
 
 Sample Output
 35
*/

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAX = 10001;
typedef pair< int, int > pii;

vector< pii > G[MAX], R[MAX];
int fromS[MAX], toT[MAX];
bool flagG[MAX], flagR[MAX];

void dijkstra(int s, vector< pii > *graph, int *dist, bool *flag) 
{
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0,s));
	int u, v, w, i, sz;
	dist[s] = 0;
	while(!Q.empty()) 
    {
		u = Q.top().second;
		Q.pop();
		if(flag[u]) 
            continue;
		sz = graph[u].size();
		for(i = 0; i < sz; i++) 
        {
			v = graph[u][i].second;
			w = graph[u][i].first;
			if(!flag[v] && dist[v] > dist[u] + w)
            {
				dist[v] = dist[u] + w;
				Q.push(pii(dist[v], v));
			}
		}
		flag[u] = true;
	}
}

int main()
{
	int t, n, e, u, v, w, i, k, s, f, best;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d%d", &n, &e);
		for(i = 1; i <= n; i++)
        {
			G[i].clear();
			R[i].clear();
			fromS[i] = toT[i] = INF;
			flagG[i] = flagR[i] = false;
		}
		scanf("%d%d%d", &k, &s, &f);
		for(i = 0; i < e; i++) 
        {
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(pii(w,v));
			R[v].push_back(pii(w,u));
		}
		dijkstra(s, G, fromS, flagG);
		dijkstra(f, R, toT, flagR);
		best = INF;
		while(k--) 
        {
			scanf("%d%d%d", &u, &v, &w);
			best = min(best, min(fromS[f], min(fromS[u] + w + toT[v], fromS[v] + w + toT[u])));
		}
		if(best < INF) 
            printf("%d\n", best);
		else 
            printf("-1\n");
	}
	return 0;
}
