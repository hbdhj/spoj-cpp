//
//  1436.cpp
//  
//
//  Created by Haijun Deng on 12-12-25.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int i, nodeNum, edgeNum, firstNode, secondNode;
    cin>>nodeNum;
    cin>>edgeNum;
    cout<<"nodeNum = "<<nodeNum<<", edgeNum = "<<edgeNum<<endl;
    multimap<int,int> edges;
    multimap<int,int>::iterator it;
    pair<multimap<int,int>::iterator,multimap<int,int>::iterator> ret;
    for(i=0;i<edgeNum;i++)
    {
        cin>>firstNode;
        cin>>secondNode;
        pair<int, int> edge1(firstNode, secondNode);
        edges.insert(edge1);
        //pair<int, int> edge2(secondNode, firstNode);
        //edges.insert(edge2);
    }
    for(i=0;i<nodeNum;i++)
    {
        ret = edges.equal_range(i+1);
        //if(ret!=edges.end())
        {
            vector<int> checked(nodeNum, 0);
            cout<<(i+1)<<" connect to ";
            for (it=ret.first; it!=ret.second; ++it)
            {
                checked[i+1]=1;
                while()
                {
                }
                cout << " " << (*it).second;
            }
            cout<<endl;
        }
    }
    return 0;
}