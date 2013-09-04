//
//  15783_CODERE3.cpp
//  
//
//  Created by Haijun Deng on 13-9-2.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Task: Coder Express 3!!
 Sample input:
 
 2
 10
 1 3 5 6 4 8 4 3 2 1
 6
 8 6 3 4 2 1
 
 Sample Output:
 
 9
 5
 
 Explanation
 
 for first test case the subsequence is : 1 3 5 6 8 4 3 2 1 for second case it is : 8 6 4 2 1
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, i, j;
    scanf("%d", &t);
    for (i=0; i<t; i++) {
        scanf("%d", &n);
        vector<int> list(n);
        for (j=0; j<n; j++) {
            scanf("%d", &list[j]);
            
        }
    }
    return 0;
}