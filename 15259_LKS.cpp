//
//  15259_LKS.cpp
//  
//
//  Created by Haijun Deng on 13-6-29.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Large Knapsack
 ALGO: dynamic programming
 */
#include <iostream>
#include <string.h>

int Vi[500];
int Wi[500];
//int pack[500][2000000];
int pack[500][2000];
int main()
{
    int K, N;
    scanf("%d %d", &K, &N);
    memset(Vi, 0, sizeof(Vi));
    memset(Wi, 0, sizeof(Wi));
    memset(pack, 0, sizeof(pack));
    
    for (int i=0; i<N; i++)
    {
        scanf("%d %d",&Vi[i], &Wi[i]);
    }
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=K; j++)
        {
            if (Wi[i-1]>j) 
            {
                pack[i][j]=pack[i-1][j];
            }
            else
            {
                pack[i][j]=pack[i-1][j]>((Vi[i-1] + pack[i-1][j-Wi[i-1]]))?pack[i-1][j]:((Vi[i-1] + pack[i-1][j-Wi[i-1]]));
            }
        }
    }
    printf("%d\n",pack[N][K]);
    return 0;
}