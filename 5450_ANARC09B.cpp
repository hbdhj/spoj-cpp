//
//  5450_ANARC09B.cpp
//
//
//  Created by Haijun Deng on 13-4-8.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: match, gcd, lcm
 Input:
 2 3
 1 2
 0 0

 Output:
 6
 2
 */
#include <cstdio>
using namespace std;


long long gcd( long long a, long long b )
{
	if(b)
        return gcd( b, a % b );
	return a;
}

long long lcm( long a, long b )
{
	return a / gcd( a, b ) * b;
}

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b)==2 && a + b)
    {
		long long lcmv = lcm(a, b);
		printf("%lld\n", ( lcmv / a ) * ( lcmv / b ) );
	}
	return 0;
}
