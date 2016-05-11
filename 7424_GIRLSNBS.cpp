//
//  7424.cpp
//
//
//  Created by Haijun Deng on 13-1-16.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 10 10
 5 1
 0 1000
 -1 -1

 Output:
 1
 3
 1000
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void arrage(int b, int s)
{
    /*if(s>(b-2))
        printf("1\n");
    else if(s==0)
        printf("%d\n", b);
    else
        printf("%d\n", b-s-1);*/
    int ret=ceil(float(b)/(s+1));
    printf("%d\n", ret);
}

int main()
{
    int g, b;
    vector<int> ss;
    scanf("%d %d", &g, &b);
    while (g!=-1&&b!=-1) {
        ss.push_back(g);
        ss.push_back(b);
        scanf("%d %d", &g, &b);
    }
    for (int i=0; i<ss.size()/2; i++) {
        if (ss[i*2]>ss[i*2+1])
            arrage(ss[i*2], ss[i*2+1]);
        else
            arrage(ss[i*2+1], ss[i*2]);
    }
    return 0;
}
