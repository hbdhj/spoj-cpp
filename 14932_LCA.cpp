//
//  14932_LCA.cpp
//  
//
//  Created by Haijun Deng on 13-5-20.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Lowest Common Ancestor
 Input:
 1
 7
 3 2 3 4
 0
 3 5 6 7
 0
 0
 0
 0
 4
 5 7
 2 7
 3 6
 1 7
 Output:
 Case 1:
 3
 1
 */
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;
	
    for (int ti=0;ti<t;ti++)
    {
        int n;
        //cin>>n;
        scanf("%d", &n);
        //vector<vector<int>> ancestor(n, vector<int>(0,0));
        vector<vector<int> > ancestors(n);
        for(int i=0;i<n;i++)
        {
        	ancestors[i].push_back(i);
        }
		for(int i=0;i<n;i++)
        {
        	int m;
            scanf("%d", &m);
			for(int j=0;j<m;j++)
        	{
        		int nd;
        		scanf("%d", &nd);
				ancestors[nd-1].push_back(i);
			}
		}
		/*for(int i=0;i<n;i++)
        {
        	printf("%d's ancestor is :", i+1);
			for(int j=0;j<ancestors[i].size();j++)
				printf(" %d", ancestors[i][j]+1);
			printf("\n");
		}*/
        int l;
        scanf("%d", &l);
        vector<pair<int, int> > queries;
        for(int i=0;i<l;i++)
        {
            int s_n,t_n;
            scanf("%d %d", &s_n, &t_n);
			queries.push_back(pair<int, int>(s_n-1, t_n-1));
        }
		printf("Case %d:\n",ti+1);
		for(int i=0;i<l;i++)
        {
            if(ancestors[queries[i].first].size()==1)
            {
            	printf("%d\n", queries[i].first+1);
				continue;
            }
			if(ancestors[queries[i].second].size()==1)
            {
            	 printf("%d\n", queries[i].second+1);
				continue;
            }
			int s_n=queries[i].first;
			int t_n=queries[i].second;
			
			if(ancestors[s_n].size()==2)
			{
				int ans=ancestors[s_n][1];
				while(ancestors[ans].size()>1)
				{
					//printf("%d have %d ancestors\n", ans, ancestors[ans].size());
					ancestors[s_n].push_back(ancestors[ans][1]);
					ans=ancestors[ans][1];
				}
			}
			//printf("%d have %d ancestors\n", s_n+1, ancestors[s_n].size());
			if(ancestors[t_n].size()==2)
			{
				int ans=ancestors[t_n][1];
				while(ancestors[ans].size()>1)
				{
					//printf("%d have %d ancestors\n", ans, ancestors[ans].size());
					ancestors[t_n].push_back(ancestors[ans][1]);
					ans=ancestors[ans][1];
				}
			}
			/*for(int l=0;l<n;l++)
        	{
        		printf("%d's ancestor is :", l+1);
				for(int j=0;j<ancestors[l].size();j++)
					printf(" %d", ancestors[l][j]+1);
				printf("\n");
			}*/
			//printf("%d have %d ancestors\n",t_n+1, ancestors[t_n].size());
			int s_n_i, t_n_i;
			for(s_n_i=ancestors[s_n].size()-1, t_n_i=ancestors[t_n].size()-1; 
				s_n_i>=0&&t_n_i>=0; s_n_i--, t_n_i--)
			{
				//printf("ancestors[%d][%d] = %d, ancestors[%d][%d] = %d\n", s_n, s_n_i, ancestors[s_n][s_n_i]+1, t_n, t_n_i, ancestors[t_n][t_n_i]+1);
				if(ancestors[s_n][s_n_i]!=ancestors[t_n][t_n_i])
					break;
			}
			printf("%d\n", ancestors[s_n][s_n_i+1]+1);
        }
	}
	return 0;
}