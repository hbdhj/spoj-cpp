/*
6288. Treeramids
Input:
2
7
0 1
2 0
0 3
2 4
5 2
6 3
3
1 2
1 0

Output:
25
9
*/
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int bfs(vector<vector<int> > &edges, vector<int> &res, int node, int root)
{
    int ret=1;
    for(int i=0;i<edges[node].size();i++)
    {
        if(edges[node][i]!=root)
        {
            ret+=bfs(edges,res,edges[node][i],node)+1;
        }
    }
    res[node]=ret;
    return ret;
}

int bfs(vector<vector<int> > &edges)
{
    vector<int> res(edges.size(),0);
    int ret=1;
    for(int i=0;i<edges[0].size();i++)
    {
        ret+=bfs(edges,res,edges[0][i],0)+1;
    }
    res[0]=ret;
    int total=0;
    for(int i=0;i<res.size();i++)
        total+=res[i];
    return total;
}

int main()
{
    int t,n,i,j,l;
    scanf("%d", &t);
    
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n>1)
        {
            vector<vector<int> > edges(n);
            for(j=0;j<n-1;j++)
            {
                int f,s;
                scanf("%d %d",&f, &s);
                edges[f].push_back(s);
                edges[s].push_back(f);
			}
            int ret=bfs(edges);
            printf("%d\n",ret);            
		}
        else
            printf("1\n");       
    }
	return 0;
}