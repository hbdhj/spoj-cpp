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
 0
 Output:
 1. 22
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN,i,j;
    scanf("%d", &tN);
    vector<vector<unsigned long long int> > inputs;
    while (tN) {
        vector<unsigned long long int> input(tN*3);
        for(i=0;i<3*tN;i++)
        {
            scanf("%llu", &input[i]);
        }
        inputs.push_back(input);
        scanf("%d", &tN);
    }
    for(i=0;i<inputs.size();i++)
    {
        for(j=2;j<inputs[i].size()/3-1;j++)
        {
            //left one
            if(inputs[i][3*j-3]<inputs[i][3*j-2])
                inputs[i][3*j]+=inputs[i][3*j-3];
            else
                inputs[i][3*j]+=inputs[i][3*j-2];
            //right one
            if(inputs[i][3*j-1]<inputs[i][3*j-2])
                inputs[i][3*j+2]+=inputs[i][3*j-1];
            else
                inputs[i][3*j+2]+=inputs[i][3*j-2];
            //center one
            if((inputs[i][3*j-3]<=inputs[i][3*j-2])&&(inputs[i][3*j-3]<=inputs[i][3*j-1]))
                inputs[i][3*j+1]+=inputs[i][3*j-3];
            else if((inputs[i][3*j-2]<=inputs[i][3*j-3])&&(inputs[i][3*j-2]<=inputs[i][3*j-1]))
                inputs[i][3*j+1]+=inputs[i][3*j-2];
            else if((inputs[i][3*j-1]<=inputs[i][3*j-3])&&(inputs[i][3*j-1]<=inputs[i][3*j-2]))
                inputs[i][3*j+1]+=inputs[i][3*j-1];
            //printf("%llu %llu %llu\n", inputs[i][3*j],inputs[i][3*j+1],inputs[i][3*j+2]);
        }
        // last line
        unsigned long long int min;
        int size=inputs[i].size();
        
        if(inputs[i].size()/3>2)
        {
            min=1000000000000;
            for(j=4;j<7;j++)
            {
                if(min>inputs[i][size-j])
                    min=inputs[i][size-j];
            }
        }
        else
            min=0;
        printf("%d. %llu\n", i+1, min+inputs[i][1]+inputs[i][size-2]);
    }
    return 0;
}
