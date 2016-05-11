//
//  14955_DCOWS.cpp
//
//
//  Created by Haijun Deng on 13-5-30.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Dancing Cows
 ALGO: sort
 Input:
 5 7
 10
 16
 12
 10
 13
 7
 17
 12
 10
 9
 6
 11

 Output:
 4
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    if(m==n)
    {
        long b_h,b_h_t=0;
        for(int i=0;i<n;i++)
        {

            scanf("%ld", &b_h);
            b_h_t+=b_h;
        }
        long c_h,c_h_t=0;
        for(int i=0;i<n;i++)
        {

            scanf("%ld", &c_h);
            c_h_t+=c_h;
        }
        printf("%ld\n", abs(c_h_t-b_h_t));
    }
    else if(n<m)
    {
        long b_h,b_h_t=0;
        for(int i=0;i<n;i++)
        {
            scanf("%ld", &b_h);
            b_h_t+=b_h;
        }
        vector<long> c_h_l(m,0);
        for(int i=0;i<m;i++)
        {
            scanf("%ld", &c_h_l[i]);
        }
        sort(c_h_l.begin(), c_h_l.end());
        vector<long> c_h_t_l(m-n+1,0);
        long c_h_t=0;
        for(int i=0;i<n;i++)
        {
            c_h_t+=c_h_l[i];
        }
        c_h_t_l[0]=c_h_t;
        for(int i=1;i<=m-n;i++)
        {
            c_h_t_l[i]=c_h_t_l[i-1]+c_h_l[n+i-1]-c_h_l[i-1];
        }
        long ret=abs(c_h_t_l[0]-b_h_t);
        for(int i=1;i<=m-n;i++)
        {
            if(ret>abs(c_h_t_l[i]-b_h_t))
                ret=abs(c_h_t_l[i]-b_h_t);
        }
        printf("%ld\n", ret);
    }
    else
    {
        vector<long> b_h_l(n,0);
        for(int i=0;i<n;i++)
        {
            scanf("%ld", &b_h_l[i]);
        }
        long c_h,c_h_t=0;
        for(int i=0;i<m;i++)
        {
            scanf("%ld", &c_h);
            c_h_t+=c_h;
        }
        sort(b_h_l.begin(), b_h_l.end());
        vector<long> b_h_t_l(n-m+1,0);
        long b_h_t=0;
        for(int i=0;i<m;i++)
        {
            b_h_t+=b_h_l[i];
        }
        b_h_t_l[0]=b_h_t;
        for(int i=1;i<=n-m;i++)
        {
            b_h_t_l[i]=b_h_t_l[i-1]+b_h_l[m+i-1]-b_h_l[i-1];
        }
        long ret=abs(b_h_t_l[0]-c_h_t);
        for(int i=1;i<=n-m;i++)
        {
            if(ret>abs(b_h_t_l[i]-c_h_t))
                ret=abs(b_h_t_l[i]-c_h_t);
        }
        printf("%ld\n", ret);
    }
    return 0;
}
