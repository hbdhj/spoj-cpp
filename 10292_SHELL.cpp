//
//  10292.cpp
//  
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
// Just test github
/*
TASK: Shell game
*/
#include <iostream>
#include <vector>

using namespace std;

int strToId(string str)
{
    if(str=="left")
        return 0;
    else if(str=="center")
        return 1;
    else if(str=="right")
        return 2;
}

string idToStrToId(int id)
{
    if(id==0)
        return "left";
    else if(id==1)
        return "center";
    else if(id==2)
        return "right";
}

int main()
{
    int swaptimes;
    int pos[]={0,0,0};
    string initpos;
    cin>>initpos;
    cin>>swaptimes;
    vector<string> swaps;
    for(int i=0; i<2*swaptimes; i++)
    {
        string swap;
        cin>>swap;
        swaps.push_back(swap);
    }
    pos[strToId(initpos)]=1;
    
    for(int i=0; i<swaptimes; i++)
    {
        int start_pos = strToId(swaps[i*2]);
        int end_pos = strToId(swaps[i*2+1]);
        int swap_n = pos[end_pos];
        pos[end_pos]=pos[start_pos];
        pos[start_pos]=swap_n;
    }    
    for(int i=0; i<3; i++)
        if(pos[i])
            cout<<idToStrToId(i)<<endl;
    return 0;
}
