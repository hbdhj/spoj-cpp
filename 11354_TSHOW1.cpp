//
//  11354.cpp
//
//
//  Created by Haijun Deng on 13-3-2.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Amusing numbers
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        unsigned long long k;
        scanf("%llu",&k);
        k++;
        vector<int> output;
        while (k>1)
        {
            if(k%2)
                output.push_back(6);
            else
                output.push_back(5);
            k=k/2;
        }
        for (int i=output.size(); i>0; i--)
        {
            printf("%d", output[i-1]);
        }
        printf("\n");
    }
    return 0;
}
