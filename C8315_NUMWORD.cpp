//
//  C8315_NUMWORD.cpp
//
//
//  Created by Haijun Deng on 13-6-10.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Number to Word
 ALGO: easy, Recursion
 Input:
 123
 34108

 Output:
 one hundred twenty three
 thirty four thousand one hundred eight
 */

#include <iostream>
#include <vector>

using namespace std;

void print(int n)
{
    string less[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string more[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if(n>=1000)
    {
        print(n/1000);
        printf("thousand ");
        print(n%1000);
    }
    else if(n>=100)
    {
        printf("%s",less[n/100-1].c_str());
        printf(" hundred ");
        print(n%100);
    }
    else if(n>=20)
    {
        printf("%s ",more[n/10-2].c_str());
        print((n-20)%10);
    }
    else if(n)
    {
        printf("%s ",less[n-1].c_str());
    }
}

int main()
{
    int n;
    cin>>n;
    if(n)
        print(n);
    else
        printf("zero");
    printf("\n");
    return 0;
}
