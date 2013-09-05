//
//  15849_DIGOKEYS.cpp
//  
//
//  Created by Haijun Deng on 13-9-5.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Sample Input
 2
 3
 1 2
 1 3
 4
 2 2 3
 1 1
 2 2 4
 
 Sample Output
 2
 1 2
 2
 1 3
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, m, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<vector<int> > keys;
        for (i=1; i<n; i++) {
            scanf("%d", &m);
            vector<int> box(m);
            for (j=0; j<m; j++) {
                scanf("%d", &box[j]);
            }
            keys.push_back(box);
        }
    } 
    return 0;
}