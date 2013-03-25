//
//  12369.cpp
//  
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 11 + 11
 988726 - 978625
 12 * 41
 1124 / 1112
 13 * 33
 15 / 16
 
 Output:
 11 + 11 = 12
 988726 - 978625 = 919111
 12 * 41 = 42
 1124 / 1112 = 1112
 13 * 33 = 39
 15 / 16 = 10
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //cout<<"sizeof(long long int) = "<<sizeof(long long int)<<endl;
    char s1[30], ch[1], s2[30];
    while (scanf("%s %[+-*/] %s",s1,ch,s2) !=EOF) 
    {
        cout<<s1<<", "<<ch<<", "<<s2<<endl;
    }
    return 0;
}
