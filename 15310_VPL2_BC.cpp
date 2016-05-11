//
//  15310_VPL2_BC.cpp
//
//
//  Created by Haijun Deng on 13-7-11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Peter Quest
 INPUT

 OUTPUT

 3

 3 2 2
 0 0
 1 1

 3 3 3
 0 0
 1 1
 2 2

 8 8 10
 0 1
 5 0
 2 5
 4 5
 2 6
 5 6
 6 6
 5 7
 6 7
 7 7

 Scenario #1:
 *2
 2*
 11

 Scenario #2:
 *21
 2*2
 12*

 Scenario #3:
 1*1-----
 111-1221
 ----1**1
 ----2331
 11--1*32
 *1--13**
 11---2**
 -----13*
 */
#include <iostream>
#include <string.h>

char mines[6144][6144];
//char mines[10][10];

int main()
{
    int t, n, m, k, x, y, i, j, l, h, x_s, x_e, y_s, y_e;
    scanf("%d", &t);
    for (l=0; l<t; l++)
    {
        memset(mines, '0', sizeof(mines));
        scanf("%d %d %d", &n, &m, &k);
        for (h=0; h<k; h++)
        {
            scanf("%d %d",&x,&y);
            mines[x][y]='*';
            x_s = x-1>0?x-1:0;
            x_e = x+1<n-1?x+1:n-1;
            y_s = y-1>0?y-1:0;
            y_e = y+1<m-1?y+1:m-1;
            //printf("x_s = %d, x_e = %d, y_s = %d, y_e = %d\n", x_s, x_e, y_s, y_e);
            for (i=x_s; i<=x_e; i++)
            {
                for (j=y_s; j<=y_e; j++)
                {
                    if (mines[i][j]!='*')
                    {
                        mines[i][j]++;
                    }
                }
            }
        }
        printf("Scenario #%d:\n", l+1);
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (mines[i][j]=='0')
                    printf("-");
                else
                    printf("%c", mines[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
