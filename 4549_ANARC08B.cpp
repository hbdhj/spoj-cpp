//
//  4549.cpp
//  
//
//  Created by Haijun Deng on 13-1-17.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: ad-hoc
 010079010+010079=010106106
 106010+010=106093
 */
#include <iostream>
#include <vector>

using namespace std;

int chartoint(char a, char b, char c)
{
    return (a-'0')*100+(b-'0')*10+(c-'0');
}

int strtoint(string str)
{
    //printf("%s\n", str.c_str()); 
    int ret=0;
    int base=1;
    int len=str.length();
    if(len%3==0)
    {
        for(int j=0;j<len/3;j++)
        {
            int check=chartoint(str[len-j*3-3],str[len-j*3-2],str[len-j*3-1]);
            switch (check) {
                case 63:    // 0
                    break;
                case 10:    // 1
                    ret+=base;
                    break;
                case 93:    // 2
                    ret+=base*2;
                    break;
                case 79:    // 3
                    ret+=base*3;
                    break;
                case 106:    // 4
                    ret+=base*4;
                    break;
                case 103:    // 5
                    ret+=base*5;
                    break;
                case 119:    // 6
                    ret+=base*6;
                    break;
                case 11:    // 7
                    ret+=base*7;
                    break;
                case 127:    // 8
                    ret+=base*8;
                    break;
                case 107:    // 9
                    ret+=base*9;
                    break;
            }
            base*=10;
        }
    }
    return ret;
}

string inttostr(int n)
{
    string ret="";
    while (n) {
        switch (n%10) {
            case 0:
                ret="063"+ret;
                break;
            case 1:
                ret="010"+ret;
                break;
            case 2:
                ret="093"+ret;
                break;
            case 3:
                ret="079"+ret;
                break;
            case 4:
                ret="106"+ret;
                break;
            case 5:
                ret="103"+ret;
                break;
            case 6:
                ret="119"+ret;
                break;
            case 7:
                ret="011"+ret;
                break;
            case 8:
                ret="127"+ret;
                break;
            case 9:
                ret="107"+ret;
                break;
        }
        n=n/10;
    }
    return ret;
}

int main()
{
    char in[80];
    scanf("%s",in);
    string input=in;
    vector<string> inputs;
    while (input.compare("BYE")!=0) {
        inputs.push_back(input);
        scanf("%s",in);
        input=in;
    }
    for(int i=0;i<inputs.size();i++)
    {
        unsigned found = inputs[i].find('+');
        string first = inputs[i].substr(0, found);
        string second = inputs[i].substr(found+1, inputs[i].length()-found-2);
        int fir=strtoint(first);
        int sec=strtoint(second);
        int ret=fir+sec;
        //printf("%d %d %d\n", fir, sec, ret);
        string retur=inttostr(ret);
        printf("%s%s\n", inputs[i].c_str(),retur.c_str());
    }
    return 0;
}