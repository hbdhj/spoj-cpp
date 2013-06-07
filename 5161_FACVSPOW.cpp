//
//  5161_FACVSPOW.cpp
//  
//
//  Created by Haijun Deng on 13-6-7.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Factorial vs Power
 ALGO: math
 DETAILS: log(2)+log(3)+...+log(n-1)+log(n)>n*log(a);
 Input:
 3
 2
 3
 4
 
 Output:
 4
 7
 9
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 1000001

int a[MAX];

int main() 
{
	int i, j;
	double left, right, v;
	a[1] = 2;
	left = log(2.0);
	for(i=j=2; i<MAX; i++) 
    {
		v = log((double)i);
		for(++j; ;j++) 
        {
			left += log((double)j);
			right = v*j;
			if(left > right) 
            {
				a[i] = j;
				break;
			}
		}
	}
	int t, n;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
	return 0;
}