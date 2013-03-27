//
//  8001_ FIBOSUM.cpp
//  
//
//  Created by Haijun Deng on 13-3-27.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: matrix exponentiation
 Input:
 3
 0 3
 3 5
 10 19
 
 Output:
 4
 10
 10857
 */
#include <iostream>
#include <string.h>

#define i64 long long
#define CPY(d, s) memcpy(d, s, sizeof(s))

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;
const i64 MOD = 1000000007;
const i64 base[2][2] = {{1, 1}, {1, 0}};
const i64 unit[2][2] = {{1, 0}, {0, 1}};

// a = a * b
inline void mul(i64 a[2][2], i64 b[2][2]) 
{
	i64 r[2][2];
	r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
	r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
	r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
	r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;
	CPY(a, r);
}

// r = base ^ n
inline void pwr(i64 r[2][2], int n) 
{
	i64 b[2][2];
	CPY(r, unit);
	CPY(b, base);
	while(n > 0) 
    {
		if(n & 1) 
            mul(r, b);
		n >>= 1;
		mul(b, b);
	}
}

// nth fib % MOD
inline i64 fibo(int n) 
{
	i64 r[2][2];
	if(!n) return 0;
	pwr(r, n-1);
	return r[0][0];
}

int main() 
{
	int b, a, t;
	i64 sa, sb, ans;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d%d", &a, &b);
		sa = fibo(a + 1); // 0 to a-1
		sb = fibo(b + 2); // 0 to b
		ans = (sb - sa) % MOD;
		if(ans < 0) 
            ans += MOD;
		printf("%lld\n", ans);
	}
	return 0;
}