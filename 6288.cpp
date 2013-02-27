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
#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int t,n,i;
    scanf("%d", &t);
    
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n>1)
        {
            queue<pair<int, int>> edges;
            for(j=0j<n-1;j++)
            {
                int f,s;
                scanf("%d %d",&f, &s);
                edges.push_back(pair<int, int>(f,s));
            }
            vector<int> conns(n);
            for()
        }
        
    }
}