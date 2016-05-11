//
//  14891_GOODE.cpp
//
//
//  Created by Haijun Deng on 13-5-23.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Good Debugging
 Input:
 6 4 2
 2 4
 4 6
 1 1
 1 2
 Output:
 5
 4
 AC?
 2
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M, L, i, j, a, b;

    scanf("%d %d %d", &N, &M, &L);
    vector<int> lines(N, 1);
    for (i=0; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        for (j=a-1; j<b; j++)
        {
            if(lines[j])
                lines[j]=0;
            else
                lines[j]=1;
        }

        int bugs=0;
        for (j=0; j<N; j++)
        {
            if(lines[j])
                bugs++;
            if(bugs>=L)
            {
                printf("%d\n", j+1);
                break;
            }
        }
        if(bugs<L)
            printf("AC?\n");
    }
    return 0;
}
