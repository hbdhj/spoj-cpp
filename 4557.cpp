//
//  4557.cpp
//  
//
//  Created by Haijun Deng on 13-1-14.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
4557. Musical Chairs
Input:
5 3
7 1
7 2
7 3 
7 4
7 5
7 6
0 0

Output:
5 3 4
7 1 7
7 2 2
7 3 4
7 4 2
7 5 6
7 6 3 
*/

#include <iostream>
#include <vector>

using namespace std;

void musicChair(int N, int D)
{
    int ret=1;
    int m=N;
    while (m>0) {
        ret*=D;
        m--;
    }
    
    printf("%d %d %d %d\n", ret, N, D, ret%N+1);
}

int main()
{
    /*int i,N D;
    scanf("%d %d", &N, &D);
    vector<int> inputs;
    while ((N!=0)&&(D!=0)) {
        inputs.push_back(N);
        inputs.push_back(D);
        scanf("%d %d", &N, &D);
    }
    for(i=0;i<inputs.size()/2;i++)
    {
        N=inputs[i*2];
        D=inputs[i*2+1];
        musicChair(N,D);
    }*/
    musicChair(5,2);
    musicChair(5,3);
    musicChair(5,4);
    musicChair(7,3);
    musicChair(7,4);
    musicChair(7,5);
    musicChair(7,6);
    return 0;
}
