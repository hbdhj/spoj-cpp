/*
 TASK: Bitmap
 ALGO: breadth first search
 Sample input:
 1
 3 4
 0001
 0011
 0110
 
 Sample output:
 3 2 1 0
 2 1 0 0
 1 0 0 1
 */
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

#define MAX 185
#define INF (1<<30)
char grid[MAX][MAX];
int graph[MAX][MAX];
int R, C;

inline bool inRange(int i, int j)
{
	return (i>=0 && i<R && j>=0 && j<C);
}

void bfs(pair<int,int> s)
{
	pair<int, int> u;
	int d;
	queue< pair<int, int> > Q;
	Q.push(s);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(int i=(u.first-1);i<=(u.first+1);i++)
        {
			for(int j=(u.second-1);j<=(u.second+1);j++)
            {
				if(inRange(i,j))
				{
					d = abs(i-s.first) + abs(j-s.second);
					if(graph[i][j] > d)
					{
						graph[i][j] = d;
						Q.push(pair<int,int>(i,j));
					}
				}
            }
        }
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &R, &C);
		for(int i=0;i<R; i++)
            scanf("%s", grid[i]);

		for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                graph[i][j] = (grid[i][j]=='0')? INF : 0;

		for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
        		if(grid[i][j]=='1')
					bfs(pair<int,int>(i,j));

		for(int i=0;i<R;i++)
        {
			printf("%d", graph[i][0]);
			for(int j=1;j<(C-1);j++)
                printf(" %d", graph[i][j]);
			printf("\n");
		}
	}
	return 0;
}
