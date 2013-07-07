//
//  3591_PATHEADS.cpp
//  
//
//  Created by Haijun Deng on 13-6-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK:  Patting Heads	
 */
#include <cstdio>
using namespace std;


int main() 
{
    int i, j, n, mmax = -1;
    
    const int MAX = 1000001;
    const int N = 100001;
    
    int cnt[MAX], res[MAX], a[N];

    scanf("%d", &n);
    // get the input
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        mmax = a[i] > mmax? a[i] : mmax;
        cnt[a[i]]++;
    }
    for(i = 0; i < n; i++) 
    {
        if(a[i] > 1 && cnt[a[i]]) 
        {
            for(j = a[i]; j <= mmax; j += a[i])
                res[j] += cnt[a[i]];
            cnt[a[i]] = 0;
        }
    }
    for(i = 0; i < n; i++) 
        printf("%d\n", res[a[i]] - 1 + cnt[1]);
    return 0;
}
