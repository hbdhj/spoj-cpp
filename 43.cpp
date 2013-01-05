//
//  43.cpp
//  
//
//  Created by Haijun Deng on 12-12-23.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, i, j, p, n, num;
    vector<vector<int> > inputs;
    vector<int> pls;
    cin>>tN;
    for(i=0;i<tN;i++)
    {
        cin>>num;
        cin>>p;
        pls.push_back(p);
        vector<int> input;
        for(j=0;j<num;j++)
        {
            cin>>n;
            input.push_back(n);
        }
        inputs.push_back(input);
    }    
    for(i=0;i<tN;i++)
    {
        int sum, avg;
        for(j=0;j<inputs[i].size();j++)
            sum+=inputs[i][j];
        avg = sum/inputs.size();
    }
}