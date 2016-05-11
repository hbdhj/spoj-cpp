//
//  7881_C1LJUTNJ.cpp
//
//
//  Created by Haijun Deng on 13-6-4.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Ljutnja
 ALGO: sort
 Input:
 5 3
 1
 3
 2
 Output:
 1

 Input:
 10 4
 4
 5
 2
 3

 Output:
 4
 */

#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main()
{
	int n, m, i, ang;
	long long tot = 0, ans = 0;
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; i++)
    {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	tot -= m;
	sort(a, a + n);
	for(i = 0; i < n; i++)
    {
		ang = a[i]>(tot/(n-i))?(tot/(n-i)):a[i];
		ans += ang * ang;
		tot -= ang;
        //printf("ang = %d, ans = %lld, tol= %lld \n", ang, ans, tot);
	}
	printf("%lld\n", ans);
	return 0;
}
