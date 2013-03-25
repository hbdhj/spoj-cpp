//
//  3923.cpp
//  
//
//  Created by Haijun Deng on 13-1-16.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 1
 6 5
 3 1 7 4 2
 2 1 3 1 1
 1 2 2 1 8
 2 2 1 5 3
 2 1 4 4 4
 5 2 7 5 1
 
 Output:
 32 
 */
#include <iostream>
#include <vector>

using namespace std;

int maxthree(int a, int b, int c)
{
    int d=a>b?a:b;
    return d>c?d:c;
}

int main()
{
    int tN;
    int h, w;
    scanf("%d", &tN);
    vector<int> hs(tN);
    vector<int> ws(tN);
    vector<vector<int> > mss;
    for (int i=0; i<tN; i++) {
        scanf("%d %d", &hs[i], &ws[i]);
        vector<int> ms(hs[i]*ws[i]);
        for(int j=0;j<hs[i]*ws[i];j++)
        {
            scanf("%d", &ms[j]);
        }
        mss.push_back(ms);
    }
    for (int i=0; i<tN; i++) 
    {
        for (int j=1; j<hs[i]; j++) {
            mss[i][ws[i]*j]+=mss[i][ws[i]*(j-1)]>mss[i][ws[i]*(j-1)+1]?mss[i][ws[i]*(j-1)]:mss[i][ws[i]*(j-1)+1];
            mss[i][ws[i]*(j+1)-1]+=mss[i][ws[i]*j-1]>mss[i][ws[i]*j-2]?mss[i][ws[i]*j-1]:mss[i][ws[i]*j-2];
            for (int k=1; k<ws[i]-1; k++) {
                mss[i][ws[i]*j+k]+=maxthree(mss[i][ws[i]*(j-1)+k-1], mss[i][ws[i]*(j-1)+k] ,mss[i][ws[i]*(j-1)+k+1] );
            }
        }
        int max=0;
        for (int j=1; j<ws[i]+1; j++) {
            if(mss[i][ws[i]*hs[i]-j]>max)
                max=mss[i][ws[i]*hs[i]-j];
        }  
        printf("%d\n", max);
    }    
    return 0;
}
