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

/*class Node
{
public:
	int id;
	int number;
};*/

//class Leaf:public Node
class Node
{
public:
	int id;
	int number;
	vector<Node> leaves;
};

int main()
{
    int t,n,i,j,l;
    scanf("%d", &t);
    
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n>1)
        {
            vector<pair<int, int> > edges;
            vector<int> conns(n,0);
			vector<int> done(n,0);
            for(j=0;j<n-1;j++)
            {
                int f,s;
                scanf("%d %d",&f, &s);
                edges.push_back(pair<int, int>(f,s));
				conns[f]++;
				conns[s]++;
			}
            bool all=true;
			for(j=0;j<n;j++)
            {
				printf("conns[%d] = %d\n", j, conns[j]);
				if(conns[j]==1)
				{
					done[j]=1;
				}
				else
				{
					all=false;
				}
            }
			int count=0;
			while(all==false)
			{
				all=true;
				for(j=0;j<n;j++)
				{
					printf("done[%d] = %d\n", j, done[j]);
					if(done[j]==0)
					{
						int total=0;
						bool got=true;
						for(l=0;l<n-1;l++)
						{
							count++;
							if(count>100)
								break;
							//printf("edges[%d].first=%d, edges[%d].second=%d\n",l,edges[l].first,l,edges[l].second);	
							if(edges[l].first==j)
							{
								if(done[edges[l].second])
									total+=done[edges[l].second]+1;
								else
								{
									got=false;
									break;
								}
							}
							else if(edges[l].second==j)
							{
								if(done[edges[l].first])
									total+=done[edges[l].first]+1;
								else
								{
									got=false;
									break;
								}
							}
							
						}
						if(got)
						{
							done[j]=total+1;
							printf("set done[%d]=%d\n",j,total+1);
						}	
						else
						{
							all=false;
							break;
						}
					}
				}
			}
			int max=0;
			for(j=0;j<n;j++)
			{
				max+=done[j];
			}
			printf("%d\n",max);
		}
    }
	return 0;
}