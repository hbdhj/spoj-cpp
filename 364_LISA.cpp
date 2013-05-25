//
//  364_LISA.cpp
//  
//
//  Created by Haijun Deng on 13-5-25.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 2
 1+2*3+4*5
 2+1*0*1+1 
 
 Output:
 105 27
 3 0
 
 Two possible expressions for the first testcase:
 
 105 = (1+2)*(3+4)*5
 27  = 1+2*3+4*5

 */
#include <iostream>

using namespace std;

unsigned long long solve1(string str)
{
    //cout<<"solve1 str = "<<str<<endl;
    size_t foundStar = str.find('*');
    size_t foundPlus = str.find('+');
    if (foundStar!=string::npos)
    {
        string strL=str.substr(0, foundStar);
        string strR=str.substr(foundStar+1);
        //cout<<"strL = "<<strL<<", strR = "<<strR<<endl;
        return solve1(strL)*solve1(strR);
    }
    else if(foundPlus!=string::npos)
    {
        string strL=str.substr(0, foundPlus);
        string strR=str.substr(foundPlus+1);
        //cout<<"strL = "<<strL<<", strR = "<<strR<<endl;
        return solve1(strL)+solve1(strR);
    }
    else
    {
        int ret;
        sscanf(str.c_str(), "%d", &ret);
        return ret;
    }
};

unsigned long long solve2(string str)
{
    //cout<<"str = "<<str<<endl;
    size_t foundStar = str.find('*');
    size_t foundPlus = str.find('+');
    if(foundPlus!=string::npos)
    {
        string strL=str.substr(0, foundPlus);
        string strR=str.substr(foundPlus+1);
        //cout<<"strL = "<<strL<<", strR = "<<strR<<endl;
        return solve2(strL)+solve2(strR);
    }
    else if (foundStar!=string::npos)
    {
        string strL=str.substr(0, foundStar);
        string strR=str.substr(foundStar+1);
        //cout<<"strL = "<<strL<<", strR = "<<strR<<endl;
        return solve2(strL)*solve2(strR);
    }
    else
    {
        int ret;
        sscanf(str.c_str(), "%d", &ret);
        return ret;
    }

};

int main()
{
    int n;
    cin>>n;
    while (n--) 
    {
        string str;
        cin>>str;
        unsigned long long ret1=solve1(str);
        unsigned long long ret2=solve2(str);
        if(ret1>ret2)
            cout<<ret1<<" "<<ret2<<endl;
        else
            cout<<ret2<<" "<<ret1<<endl;
    }
    return 0;
}