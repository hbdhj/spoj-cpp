//
//  C218.cpp
//
//
//  Created by Haijun Deng on 13-1-27.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void PrintPoint(int n)
{
    if (n==2) {
        printf("%.1f %.1f %.1f\n", 0.0, 0.0, 1.0);
        printf("%.1f %.1f %.1f\n", 0.0, 0.0, -1.0);
    }
    else if(n==3)
    {
    }
    else if(n==4)
    {
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> inputs(n);
    for (int i=0; i<n; i++) {
        scanf("%d", &inputs[i]);
    }
    for (int i=0; i<n; i++) {
        PrintPoint(inputs[i]);
    }
    return 0;
}
