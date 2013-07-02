//
//  15243_VPL2_AC.cpp
//  
//
//  Created by Haijun Deng on 13-7-1.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Primos Quest
 ALGO: simulation
Input:
 3
 0 OORRBYYYGG
 1 RRORGRRRBOY
 3 RRRORORRRR
Output: 
 Scenario #1: 3
 Scenario #2: 4
 Scenario #3: 5
 */
#include <iostream>
#include <string.h>

int main()
{
    int t,C,i,j,k,l,m,n;
    char s[1000002];
    int v[1000002];
    //int d[100000];
    scanf("%d", &t);
    for (i=0; i<t; i++) 
    {
        memset(s,0,sizeof(s));
        memset(v,0,sizeof(v));
        //memset(d,0,sizeof(d));
        scanf("%d %s", &C, s);
        //printf("s=%s, C=%d,j=%d\n",s,C,j);
        j=0;
        while (s[j]!='\0') 
        {
            switch (s[j]) {
                case 'G':
                    v[j]=0;
                    break;
                case 'R':
                    v[j]=1;
                    break;
                case 'Y':
                    v[j]=2;
                    break;
                case 'B':
                    v[j]=3;
                    break;
                case 'O':
                    v[j]=4;
                    break;
                default:
                    break;
            }
            j++;
            
        }
        //printf("s=%s, C=%d,j=%d\n",s,C,j);
        v[j]=v[j-1];
        l=0;
        /*for (k=0; k<=j; k++) 
        {
            printf("%d ",v[k]);
        }
        printf("\n");
        for (k=1; k<=j; k++) 
        {
            d[k]=v[k]>v[k-1]?v[k]-v[k-1]:v[k-1]-v[k];
        }
        for (k=0; k<=j; k++) 
        {
            printf("%d ",d[k]);
        }
        printf("\n");*/
        n=0;
        for (k=0,m=0; m<j; ) 
        {
            if (n<m-k) {
                n=m-k;
            }
            if(l<=C)
            {
                l+=(v[m+1]>v[m]?v[m+1]-v[m]:v[m]-v[m+1]);
                m++;
            }
            else
            {
                l-=(v[k+1]>v[k]?v[k+1]-v[k]:v[k]-v[k+1]);
                k++;
            }
            //printf("%d ", l);
            //printf("%d ", n);
            if (n<m-k) {
                n=m-k;
            }
            //printf("%d %d %d; ", k, m, n);
        }
        //printf("\n");
        printf("Scenario #%d: %d\n", i+1, n);
    }
    return 0;
}