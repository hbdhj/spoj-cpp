//
//  15433_UCV2013E.cpp
//
//
//  Created by Haijun Deng on 13-7-26.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Greedy Walking
 Input:
 2
 2 1
 5 5
 4
 0 0 0 0
 1 2 3 4
 5
 1 2 3 4 5
 8 5 6 4 8
 5
 0 0 0 0 0
 100 100 100 100 100
 0

 Output:
 35
 12600
 19219200
 257055440
 */
#include <iostream>

#define MOL 1000000007

unsigned long long factorial[502];
int a[50];
int b[50];
int c[50];

int main()
{
    int n;
    scanf("%d", &n);
    while (n!=0) {
        for (int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i=0; i<n; i++)
        {
            scanf("%d", &b[i]);
        }
        int sum=0;
        for (int i=0; i<n; i++)
        {
            c[i]=b[i]-a[i];
            sum+=c[i];
        }
        //printf("sum = %d\n", sum);
        //unsigned long long ret=factorial[sum];
        //printf("ret = %lld\n", ret);

        //for (int i=0; i<n; i++) {
        //    ret/=factorial[c[i]];
        //}
        for (int i=0; i<=sum; i++)
        {
            factorial[i]=i;
        }
        /*for (int i=1; i<=sum; i++)
        {
            printf("%lld ", factorial[i]);
        }
        printf("\n\n");*/
        for (int i=0; i<n; i++)
        {
            for (int j=2; j<=c[i]; j++)
            {
                //printf("c[%d]=%d, j=%d\n", i, c[i], j);
                int d=j;
                for (int l=2; l<=sum; l++)
                {
                    if (factorial[l]%d==0)
                    {
                        factorial[l]/=d;
                        break;
                    }
                    else if(d%factorial[l]==0)
                    {
                        d=d/factorial[l];
                        factorial[l]=1;
                    }
                    if(j==1)
                        break;
                    //printf("factorial[%d]=%lld, j=%d\n", l, factorial[l], j);
                }
                /*for (int l=1; l<=sum; l++)
                {
                    printf("%lld ", factorial[l]);
                }
                printf("\n");*/
            }
            //printf("\n");
        }
        //printf("\n");
        unsigned long long ret = 1;
        for (int i=1; i<=sum; i++)
        {
            //printf("%lld ", factorial[i]);
            ret*=factorial[i];
            ret=ret%MOL;
        }
        //printf("\n");
        printf("%lld\n", ret);
        scanf("%d", &n);
    }
    return 0;
}
