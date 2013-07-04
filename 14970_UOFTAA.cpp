//
//  14970_UOFTAA.cpp
//  
//
//  Created by Haijun Deng on 13-5-19.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Rock Paper Scissors Fox
 */
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string inputs;
        cin>>inputs;
        if(inputs=="Foxen")
            break;
        else if(inputs=="Foxen")
        {
            
        }
        else if(inputs=="Fox")
        {
            cout<<"Foxen"<<endl;
        }
        else if(inputs=="Foxen")
        {
            cout<<"Foxen"<<endl;
        }
        else if(inputs=="Scissors")
        {
            cout<<"Rock"<<endl;
        }
        else if(inputs=="Rock")
        {
            cout<<"Paper"<<endl;
        } 
        else if(inputs=="Paper")
        {
            cout<<"Scissors"<<endl;
        }

    }
    return 0;
}
