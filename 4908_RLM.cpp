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

long long str2longlong(string str)
{
    long long ret=0;
    int length=str.length();
    for(int i=0;i<length/2;i++)
    {
        
        int digit=str[i*2+1]-'0';
        int digit_num=str[i*2]-'0';
        while (digit_num--) 
        {
            ret*=10;
            ret+=digit;
        }
    }
    return ret;
}

string longlong2str(long long ll)
{
    string ret="";
    int digit=10,digit_num=0;
    while (ll) 
    {
        if(digit==10)
        {
            digit=ll%10;
            digit_num=1;
        }
        else if(ll%10==digit)
        {
            digit_num++;
            if(digit_num==9)
            {
                char d_c='0'+digit;
                ret=d_c+ret;
                ret='9'+ret;
                
                digit=ll%10;
                digit_num=0;
            }

        }
        else
        {
            char d_c='0'+digit;
            char d_n_c='0'+digit_num;
            
            ret=d_c+ret;
            ret=d_n_c+ret;
            
            digit=ll%10;
            digit_num=1;
        }
        ll=ll/10;
    }
    char d_n_c='0'+digit_num;
    char d_c='0'+digit;
    
    ret=d_c+ret;
    ret=d_n_c+ret;
    return ret;
}

string cal(string str1, string op, string str2)
{
    string ret="";
    switch (op[0]) {
        case '+':
            ret=longlong2str(str2longlong(str1)+str2longlong(str2));
            break;
            
        case '-':
            ret=longlong2str(str2longlong(str1)-str2longlong(str2));
            break;
            
        case '*':
            ret=longlong2str(str2longlong(str1)*str2longlong(str2));
            break;
            
        case '/':
            ret=longlong2str(str2longlong(str1)/str2longlong(str2));
            break;
            
        default:
            break;
    }
    return ret;
}

int main()
{
    //cout<<"sizeof(long long int) = "<<sizeof(long long int)<<endl;
    char s1[30], ch[1], s2[30];
    while (scanf("%s %[+-*/] %s",s1,ch,s2) !=EOF) 
    {
        //cout<<s1<<", "<<ch<<", "<<s2<<endl;
        string str1=s1;
        string str2=s2;
        string op=ch;
        cout<<cal(str1, op, str2)<<endl;
    }
    /*cout<<"longlong2str(1111111111111) = "<<longlong2str(1111111111111)<<endl;
    cout<<"11 + 11 = "<<cal("11", "+", "11")<<endl;
    cout<<"988726 - 978625 = "<<cal("988726", "-", "978625")<<endl;
    cout<<"12 * 41 = "<<cal("12", "*", "41")<<endl;
    cout<<"1124 / 1112 = "<<cal("1124", "/", "1112")<<endl;*/
    return 0;
}
