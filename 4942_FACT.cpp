//
//  4942_FACT.cpp
//  
//
//  Created by Haijun Deng on 13-4-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: math, prime
 Input:
 3111989
 13091989
 77145199750673
 0
 
 Output:
 317^1 9817^1
 17^2 89^1 509^1
 328439^1 234884407^1
 */

#include <stdio.h>

#define MAX 31629376
#define LMT 5624
#define LEN 1952340

unsigned flag[MAX/64];
unsigned primes[LEN];
unsigned primelen;

#define chk(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define set(n) (flag[n>>6]|=(1<<((n>>1)&31)))
#define sq(x) ((x)*(x))

void sieve()
{
	unsigned i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!chk(i))
			for(j=i*i,k=i<<1; j<MAX; j+=k)
				set(j);
	primes[(j=0)++] = 2;
	for(i=3; i<MAX; i+=2)
		if(!chk(i))
			primes[j++] = i;
	primelen = j;
}

void factor(long long n)
{
	unsigned i, cnt, f=0;
	for(i=0; i<primelen && sq(primes[i])<=n; i++)
	{
		if(n % primes[i] == 0)
		{
			cnt = 0;
			while(n % primes[i] == 0)
			{
				cnt++;
				n /= primes[i];
			}
			printf("%s%u^%u",(f?" ":""), primes[i], cnt);
			f = 1;
		}
	}
	if(n>1) printf("%s%lld^1",(f?" ":""), n);
}

int main()
{
	long long n;
	sieve();
	while(scanf("%lld", &n)==1 && n)
	{
		factor(n);
		printf("\n");
	}
	return 0;
}