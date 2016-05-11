//
//  423_ ASSIGN.cpp
//
//
//  Created by Haijun Deng on 13-3-14.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 3
 3
 1 1 1
 1 1 1
 1 1 1
 11
 1 0 0 1 0 0 0 0 0 1 1
 1 1 1 1 1 0 1 0 1 0 0
 1 0 0 1 0 0 1 1 0 1 0
 1 0 1 1 1 0 1 1 0 1 1
 0 1 1 1 0 1 0 0 1 1 1
 1 1 1 0 0 1 0 0 0 0 0
 0 0 0 0 1 0 1 0 0 0 1
 1 0 1 1 0 0 0 0 0 0 1
 0 0 1 0 1 1 0 0 0 1 1
 1 1 1 0 0 0 1 0 1 0 1
 1 0 0 0 1 1 1 1 0 0 0
 11
 0 1 1 1 0 1 0 0 0 1 0
 0 0 1 1 1 1 1 1 1 1 1
 1 1 0 1 0 0 0 0 0 1 0
 0 1 0 1 0 1 0 1 0 1 1
 1 0 0 1 0 0 0 0 1 0 1
 0 0 1 0 1 1 0 0 0 0 1
 1 0 1 0 1 1 1 0 1 1 0
 1 0 1 1 0 1 1 0 0 1 0
 0 0 1 1 0 1 1 1 1 1 1
 0 1 0 0 0 0 0 0 0 1 1
 0 1 1 0 0 0 0 0 1 0 1

 Output:
 6
 7588
 7426
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t,n,i,j;
    scanf(""%De,&t);
    while (t--)
    {
        scanf("%d", &n);
        vector<vector<int> > topics(n,vector<int>(n,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&topics[i][j]);
            }
        }
    }
    return 0;
}
