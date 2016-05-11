//
//  8061.cpp
//
//
//  Created by Haijun Deng on 13-1-13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 SAMPLE INPUT
 3
 3 1
 2 5 4
 3 2
 5 2 4
 3 3
 2 5 4
 SAMPLE OUTPUT
 0
 1
 3
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tN,i,j,N;
    scanf("%d",&tN);
    vector<int> ks(tN);
    vector<vector<long> > hss;
    for (i=0; i<tN; i++) {
        scanf("%d %d", &N, &ks[i]);
        vector<long> hs(N);
        for (j=0; j<N; j++) {
            scanf("%ld", &hs[j]);
        }
        hss.push_back(hs);
    }
    for (i=0; i<tN; i++) {
        sort(hss[i].begin(), hss[i].end());
        long large=hss[i][hss[i].size()-1]-hss[i][0];
        for(j=ks[i]-1;j<hss[i].size();j++)
        {
            if((hss[i][j]-hss[i][j-ks[i]+1])<large)
                large=hss[i][j]-hss[i][j-ks[i]+1];
        }
        printf("%ld\n",large);
    }
    return 0;
}
