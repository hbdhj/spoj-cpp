//
//  15995_MCUR98.cpp
//
//
//  Created by Haijun Deng on 13-9-18.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Self Numbers
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define SIZE 1000000
int a[SIZE];
void self()
{
    int i,j,k;
    for(k=1;k<SIZE;k++)
    {
         i=k;
         j=i;
         while(i>0)
         {
             j+=i%10;
             i/=10;
         }
         a[j]=1;
    }
}

int main()
{
    int i,j;
    memset(a,0,sizeof(a));
    self();
    for(i=1;i<SIZE;i++)
    {
        if(a[i]==0)
             printf("%d\n",i);
     }
}
