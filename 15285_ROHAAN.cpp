//
//  15285_ROHAAN.cpp
//
//
//  Created by Haijun Deng on 13-6-28.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Defend The Rohan
 ALGO: Floyd-Warshall
 Input:
 1
 3
 0 1 1
 1 0 1
 1 9 0
 2
 2 1
 3 2
 Output:
 Case #1: 3
 */
#include <iostream>
#include <string.h>

int path[50][50];

void getPath(int n)
{
    if(n<51)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                scanf("%d", &path[i][j]);
            }
        }
    }
}

void Floyd(int n)
{
    if(n<51)
    {
        for (int k=0; k<n; k++)
        {
            for (int i=0; i<n; i++)
            {
                if (i!=k)
                {
                    for (int j=0; j<n; j++)
                    {
                        if (j!=i&&j!=k&&path[i][k]+path[k][j]<path[i][j])
                        {
                            path[i][j]=path[i][k]+path[k][j];
                        }
                    }
                }
            }
        }
    }
}
/*void printPath(int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}*/
int main()
{
    int tN,n,r,d,s,t;
    scanf("%d",&tN);
    for (int i=0; i<tN; i++)
    {
        memset(path, 0, sizeof(path));
        scanf("%d",&n);
        getPath(n);
        //printPath(n);
        Floyd(n);
        //printPath(n);
        scanf("%d",&r);
        d=0;
        while (r--)
        {
            scanf("%d %d", &s, &t);
            d+=path[s-1][t-1];
            //printf("d = %d\n",d);
        }
        printf("Case #%d: %d\n", i+1, d);
    }
    return 0;
}
