//
//  15994_BOXSCHOC.cpp
//  
//
//  Created by Haijun Deng on 13-9-18.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Boxes of Chocolate
 Input:
 2
 5
 1 2 3 4 5
 2
 1 5 1
 1 5 2
 5
 12 32 5 12 9
 3
 1 5 2
 3 5 3
 2 5 2
 Output: 
 Case 1:
 5
 2
 Case 2:
 3
 2
 2
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, i, j, n, a, b, k, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> A(n, 0);
        for(i=0; i<n; i++)
        {
            scanf("%d", &A[i]);
        }
        scanf("%d", &k);
        for(i=0; i<k; i++)
        {
            scanf("%d %d %d", &a, &b, &k);
            c=0;
            for (j=a-1; j<b; j++) 
            {
                if (A[j]%k==0) {
                    c++;
                }
            }
            printf("%d\n", c);
        }    
    }
    return 0;
}
