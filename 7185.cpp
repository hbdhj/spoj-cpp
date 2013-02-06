//
//  7185.cpp
//  
//
//  Created by Haijun Deng on 13-2-6.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 7185. Bye Bye Cakes
 Input:
 2 3 4 5 1 1 1 1
 3 6 9 0 1 2 3 4
 -1 -1 -1 -1 -1 -1 -1 -1
 Output:
 3 2 1 0
 0 0 0 12
 */
#include <iostream>
#include <vector>

using namespace std;

int maxid(float e,float f,float s, float m)
{
    if(e>=f&&e>=s&&e>=m)
        return 0;
    else if(f>=e&&f>=s&&f>=m)
        return 1;
    else if(s>=e&&s>=f&&s>=m)
        return 2;
    else if(m>=f&&m>=s&&m>=e)
        return 3;
    
}

int gcd(int a, int b)
{
    if (b==0) {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int gtd(int a, int b)
{
    int c=gcd(a,b);
    return a*b/c;
}

int cakes(int e,int f,int s, int m, int es, int fs, int ss, int ms)
{
    //printf("%d %d %d %d %d %d %d %d",e,f,s,m,es,fs,ss,ms);
    float ed=float(e/es);
    float fd=float(f/fs);
    float sd=float(s/ss);
    float md=float(m/ms);
    int mid=maxid(ed, fd, sd, md);
    int times;
    switch (mid) {
        case 0:
            times=gtd(e,es)/es;
            break;
        case 1:
            times=gtd(f,fs)/fs;
            break;
        case 2:
            times=gtd(s,ss)/ss;
            break;
        case 3:
            times=gtd(m,ms)/ms;
            break;
    }
    printf("%d %d %d %d\n",es*times-e,fs*times-f,ss*times-s,ms*times-m);
    return 0;
}

int main()
{
    int E, F, S, M, Es, Fs, Ss, Ms;
    vector<int> ES,FS,SS,MS,ELs,FLs,SLs,MLs;
    scanf("%d %d %d %d %d %d %d %d",&E,&F,&S,&M,&Es,&Fs,&Ss,&Ms);
    while (E!=-1) {
        ES.push_back(E);
        FS.push_back(F);
        SS.push_back(S);
        MS.push_back(M);
        ELs.push_back(Es);
        FLs.push_back(Fs);
        SLs.push_back(Ss);
        MLs.push_back(Ms);
        scanf("%d %d %d %d %d %d %d %d",&E,&F,&S,&M,&Es,&Fs,&Ss,&Ms);
    }
    for(int i=0;i<ES.size();i++)
    {
        cakes(ES[i],FS[i],SS[i],MS[i],ELs[i],FLs[i],SLs[i],MLs[i]);
    }
    return 0;
}
