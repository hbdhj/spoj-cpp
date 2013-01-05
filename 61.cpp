//
//  61.cpp
//  
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 4
 ()((
 4
 4
 0
 2
 0
 [and 9 test cases more]
 Output:
 Test 1:
 YES
 NO
 */
#include <iostream>
#include <vector>

using namespace std;

int actionCheck(string str, vector<int> act)
{
    if(str.length()%2!=0)
    {
        for(int i=0;i<act.size();i++)
        {
            if(act[i]==0)
            {
                cout<<"No"<<endl;
            }
        }
    }
    else
    {
        vector<int> init(str.length(),0);
        if(str[0]=='(')
            init[0]= 1;
        else if (str[0]==')')
            init[0] = -1;
        for(int i=1;i<str.length();i++)
        {
            if(str[i]=='(')
                init[i]=init[i-1]+1;
            else if(str[i]==')')
                init[i]=init[i-1]-1;
        }
        int total = init[str.length()-1];
        for(int i=0;i<act.size();i++)
        {
            if(act[i]==0)
            {
                if (total)
                {
                    cout<<"No"<<endl;
                }
                else
                {
                    
                    if (str[0]==')')
                    {
                        cout<<"No"<<endl;
                    }
                    else
                    {
                        init[0]=1;
                        bool belowZero=false;
                        for(int i=1;i<str.length();i++)
                        {
                            if(str[i]=='(')
                                init[i]=init[i-1]+1;
                            else if(str[i]==')')
                                init[i]=init[i-1]-1;
                            if(init[i]<0)
                            {
                                belowZero=true;
                                break;
                            }
                        }
                        if(belowZero)
                            cout<<"No"<<endl;
                        else
                            cout<<"Yes"<<endl;
                    }
                    
                }
            }
            else
            {
                if(str[act[i]-1]=='(')
                {
                    total-=2;
                    str[act[i]-1]=')';
                }
                else
                {    
                    total+=2;
                    str[act[i]-1]='(';
                }
            }
        }
    }
    return 0;
}

int main()
{
    int bracketNum, actionNum, i, j;
    int tN = 10;
    vector<string> backets;
    vector<vector<int> > actions;
    for(i=0;i<tN;i++)
    {
        cin>>bracketNum;
        string str;
        cin>>str;
        backets.push_back(str);
        cin>>actionNum;
        vector<int> action;
        for(j=0;j<actionNum;j++)
        {
            int act;
            cin>>act;
            action.push_back(act);
        }
        actions.push_back(action);
    }
    for(i=0;i<tN;i++)
    {
        cout<<"Test "<<i+1<<":"<<endl;
        actionCheck(backets[i], actions[i]);
    }
    return 0;
}