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
 2
 5 7
 2 7
 
 Output:
 Case 1:
 3
 1
 */
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
            scanf("%d", &m);
			for(int j=0;j<m;j++)
        	{
        		int nd;
        		scanf("%d", &nd);
				ancestor[nd-1].push_back(i);
			}
        }
        int m;
        scanf("%d", &m);
        vector<pair<int, int>> queries;
        for(int i=0;i<m;i++)
        {
            int s_n,t_n;
            scanf("%d %d", &s_n, &t_n);
			queries.push_back(pair<int, int>(s_n, t_n));
        }
		for(int i=0;i<m;i++)
        {
            printf("Case %d 0\n",ti+1);
        }
	}
	return 0;
}