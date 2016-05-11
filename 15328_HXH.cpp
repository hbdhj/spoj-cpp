//
//  15328_HXH.cpp
//
//
//  Created by Haijun Deng on 13-7-17.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Hunter x Hunter
 Input test:
 1
 5
 ..*..
 .*..*
 #...*
 ..*..
 .....

 Output test:
 3
 */
#include <iostream>

int map[500][500];

int main()
{
    int t,n,i,j,k;
    char line[500];
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d", &n);
        for (i=0; i<n; i++) {
            scanf("%s", line);
            for (j=0; j<n; j++) {
                switch (line[j]) {
                    case '.':
                        map[i][j]=0;
                        break;
                    case '*':
                        map[i][j]=1;
                        break;
                    case '#':
                        map[i][j]=-10000;
                        break;
                    default:
                        break;
                }
            }
        }
        /*for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                printf("%7d", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        for (i=1; i<n; i++) {
            map[0][i]+=map[0][i-1];
            map[i][0]+=map[i-1][0];
            map[n-1][n-1-i]+=map[n-1][n-i];
            map[n-1-i][n-1]+=map[n-i][n-1];
        }
        /*for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                printf("%7d", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        for (i=1; i<n-2; i++) {
            for (j=1; j<n-1-i; j++) {
                map[i][j]+=map[i-1][j]>map[i][j-1]?map[i-1][j]:map[i][j-1];
            }
        }
        for (i=n-2; i>1; i--) {
            for (j=n-2; j>n-i-1; j--) {
                map[i][j]+=map[i+1][j]>map[i][j+1]?map[i+1][j]:map[i][j+1];
            }
        }
        /*for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                printf("%7d", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        for (i=1; i<n-1; i++) {
            map[i][n-i-1]+=map[i-1][n-i-1]>map[i][n-i-2]?map[i-1][n-i-1]:map[i][n-i-2];
            map[i][n-i-1]+=map[i+1][n-i-1]>map[i][n-i]?map[i+1][n-i-1]:map[i][n-i];
        }
        /*for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                printf("%7d", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        int max = -10000;
        for (i=0; i<n; i++) {
            if(map[i][n-1-i]>max)
                max=map[i][n-1-i];
        }
        if (max<0)
            printf("-1\n");
        else
            printf("%d\n",max);
    }
    return 0;
}
