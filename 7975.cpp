//
//  7975.cpp
//  
//
//  Created by Haijun Deng on 13-1-13.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
4
13 7 5
7 13 6
14 3 12
15 6 16
2
-1 -1 -1
-1 -1 -1
4
-1 -2 -3
-4 -5 -6
-1 -2 -3
-7 -6 -5
0
 Output:
1. 22
2. -3
3. -32

 */
#include <iostream>
#include <vector>

using namespace std;

long long int minintwos(long long int a, long long int b)
{
    return a>b?b:a;
}

long long int mininthrees(long long int a, long long int b, long long int c)
{
    long long int min1=a>b?b:a;
    return c>min1?min1:c;
}

long long int mininfours(long long int a, long long int b, long long int c, long long int d)
{
    long long int min1=mininthrees(a,b,c);
    return min1>d?d:min1;
}

int main()
{
    int tN,i,j;
    scanf("%d", &tN);
    //vector<vector<unsigned long long int> > inputs;
    vector<vector<long long int> > inputs;
    while (tN) {
        //vector<unsigned long long int> input(tN*3);
        vector<long long int> input(tN*3);
        for(i=0;i<3*tN;i++)
        {
            scanf("%lld", &input[i]);
        }
        inputs.push_back(input);
        scanf("%d", &tN);
    }
    for(i=0;i<inputs.size();i++)
    {
        //first line
        if(inputs[i][1]<0)
            inputs[i][2]+=inputs[i][1];
        //second line
        inputs[i][3]+=inputs[i][1];
        if(inputs[i][2]<0)
        {
            inputs[i][4]+=mininthrees(inputs[i][1], inputs[i][2], inputs[i][3]);
            inputs[i][5]+=mininthrees(inputs[i][1], inputs[i][2], inputs[i][4]);
        }
        else
        {
            inputs[i][4]+=minintwos(inputs[i][1], inputs[i][3]);
            inputs[i][5]+=minintwos(inputs[i][1], inputs[i][4]);
        }
        // laters
        for(j=2;j<inputs[i].size()/3;j++)
        {
            inputs[i][3*j]+=inputs[i][3*j-2]>inputs[i][3*j-3]?inputs[i][3*j-3]:inputs[i][3*j-2];
            inputs[i][3*j+1]+=mininfours(inputs[i][3*j-3], inputs[i][3*j-2], inputs[i][3*j-1],inputs[i][3*j]);
            inputs[i][3*j+2]+=mininthrees(inputs[i][3*j+1], inputs[i][3*j-2], inputs[i][3*j-1]);
        }
        // print output
        int size=inputs[i].size();
        printf("%d. %lld\n", i+1, inputs[i][size-2]);
    }
    return 0;
}
