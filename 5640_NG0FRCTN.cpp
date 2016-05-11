//
//  5640_ NG0FRCTN.cpp
//
//
//  Created by Haijun Deng on 13-3-22.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#define u64 unsigned long long
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

void search(u64 L, u64 R, u64 T, u64 &p, u64 &q)
{
	u64 M;
	while(L<R)
	{
		M = (L+R) >> 1;
		if(T<=M)
		{
			q = p + q;
			R = M;
		}
		else
		{
			p = p + q;
			L = M + 1;
		}
	}
}

int main()
{
	u64 n, a[40] = {1}, total, target, p, q;
	int k, i;
	for(k=1; a[k-1] < 10000000000ULL; k++)
		a[k] = a[k-1] + (1ULL << k);
	while(scanf("%llu", &n)==1 && n)
	{
		for(i=0; i<k && a[i]<n; i++);
		total = 1ULL << i;
		target = total - a[i] + n;
		p = q = 1ULL;
		search(1, total, target, p, q);
		printf("%llu/%llu\n", p, q);
	}
	return 0;
}
