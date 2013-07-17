//
//  15328_HXH.cpp
//  
//
//  Created by Haijun Deng on 13-7-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
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
        for (i=0; i<n-2; i++) 
        {
            for (j=0; j<i+2; j++) 
            {
                if (j==0) {
                    //map[j][i+1-j]+=map[j][i-j];
                    map[n-1][n-j-2]+=map[n-1][n-j-1];
                }
                else if(i+1-j==0)
                {
                    //map[j][i+1-j]+=map[j-1][i+1-j];
                    map[n-2-j][n-1]+=map[n-1-j][n-1];
                }
                else
                {
                    //map[j][i+1-j]+=map[j-1][i+1-j]>map[j][i-j]?map[j-1][i+1-j]:map[j][i-j];
                    map[n-1-j][n-1-i+j]+=map[n-2-j][n-1-i+j]>map[j][i-j]?map[j-1][i+1-j]:map[j][i-j];
                }
            }
            for (k=0; k<n; k++) {
                for (j=0; j<n; j++) {
                    printf("%7d", map[k][j]);
                }
                printf("\n");
            }
            printf("\n");
        }        
    }
    return 0;
}