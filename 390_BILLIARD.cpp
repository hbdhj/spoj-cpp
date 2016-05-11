//
//  390.cpp
//
//
//  Created by Haijun Deng on 13-1-15.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Billiard
 Input:

 100 100 1 1 1
 200 100 5 3 4
 201 132 48 1900 156
 0 0 0 0 0

 Output:

 45.00 141.42
 33.69 144.22
 3.09 7967.81
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void output(int a, int b, int s, int m, int n)
{
    double L,V;
    L=double(a)*m*a*m;
    V=double(b)*b*n*n;
    //printf("%lf %lf\n",L, V);
    double D=sqrt(double(L+V));
    double A=atan(double(b*n)/a/m)/M_PI*180;
    printf("%.2lf %.2lf\n", A, D/s);
}

int main()
{
    int a,b,s,m,n;
    vector<int> inputs;
    scanf("%d %d %d %d %d", &a, &b, &s, &m, &n);
    while ((a!=0)&&(b!=0)&&(s!=0)&&(m!=0)&&(n!=0)) {
        inputs.push_back(a);
        inputs.push_back(b);
        inputs.push_back(s);
        inputs.push_back(m);
        inputs.push_back(n);

        scanf("%d %d %d %d %d", &a, &b, &s, &m, &n);
    }
    for(int i=0;i<inputs.size()/5;i++)
    {
        a=inputs[i*5];
        b=inputs[i*5+1];
        s=inputs[i*5+2];
        m=inputs[i*5+3];
        n=inputs[i*5+4];
        output(a,b,s,m,n);
    }
    return 0;
}
