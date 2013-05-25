//
//  11560_11560.cpp
//  
//
//  Created by Haijun Deng on 13-5-25.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

/*
 TASK: A Summatory
 ALGO: math
 Input:
 3
 2
 10
 3
 
 Output:
 10
 7942
 46
 */

#include <cstdio>

typedef long long i64;

const int MOD = 1000000003;

inline i64 mod(i64 a) 
{
	return a < MOD ? a : a % MOD;
}

int main() {
	int test, i;
	i64 sum, n, p[6], co[6] = {0, 4, 30, 50, 30, 6}, inv = 441666668;
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%lld", &n);
		for(i = 1, p[0] = 1; i <= 5; i++) 
            p[i] = mod(n * p[i-1]);
        /*for (int i=0; i<=5; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");*/
		for(i = 1; i <= 5; i++) 
            p[i] = mod(co[i] * p[i]);
		/*for (int i=0; i<=5; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");*/
		for(i = 1, sum = 0; i <= 5; i++) 
            sum = mod(sum + p[i]);
		sum = mod(sum * inv);
		printf("%lld\n", sum);
	}
	return 0;
}