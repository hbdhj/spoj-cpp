//
//  9637.cpp
//
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int move(string s, string e)
{
    //cout<<"move "<<s<<" to "<<e<<endl;
    int ret=0;
    bool diff = false;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]!=e[i])&&(diff==false))
        {
            ret++;
            diff=true;
        }
        if((s[i]==e[i])&&diff)
        {
            diff=false;
        }
    }
    return ret;
}
int main()
{
    vector<string> inputs;
    string s,e;
    cin>>s;
    cin>>e;
    while((s!="*")&&(e!="*"))
    {
        inputs.push_back(s);
        inputs.push_back(e);
        cin>>s;
        cin>>e;
    }
    /*inputs.push_back("BBNBBNBBBB");
    inputs.push_back("NNNNNBBNNB");
    inputs.push_back("BNBNB");
    inputs.push_back("NBNBN");
    inputs.push_back("BNBN");
    inputs.push_back("NBNB");
    inputs.push_back("B");
    inputs.push_back("B");*/
    for(int i=0;i<inputs.size()/2;i++)
    {
        cout<<move(inputs[i*2], inputs[i*2+1])<<endl;
    }
    return 0;
}
