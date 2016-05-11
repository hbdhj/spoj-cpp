//
//  13043.cpp
//
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
 TASK: The Mirror of Galadriel
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, i, j;
    cin>>tN;
    vector<string> inputs;
    for(i=0;i<tN;i++)
    {
        string str;
        cin>>str;
        inputs.push_back(str);
    }
    for(i=0;i<tN;i++)
    {
        for(j=0;j<inputs[i].length()/2;j++)
        {
            if(inputs[i][j]!=inputs[i][inputs[i].length()-j-1])
                break;
        }
        if(j==inputs[i].length()/2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
