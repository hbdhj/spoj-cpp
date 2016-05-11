//
//  4942_FACT.cpp
//
//
//  Created by Haijun Deng on 13-4-24.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: primes triangle (I)
 ALGO: math, prime, sieve
 Input:
 Input:
 3
 3
 23
 4
 Output:
 2 1
 4 3
 -1
 */

#include <stdio.h>
#include <map>
#include <math.h>

using namespace std;

#define MAX  31629376
//#define MAX 100000000
#define LMT 5624
#define LEN 1952340

unsigned flag[MAX/64];
unsigned primes[LEN];
unsigned primelen;
map<unsigned, unsigned> primemap;

#define chk(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define set(n) (flag[n>>6]|=(1<<((n>>1)&31)))
#define sq(x) ((x)*(x))

void sieve()
{
	unsigned i, j, k;
	for(i=3; i<LMT; i+=2)
    {
		if(!chk(i))
        {
			for(j=i*i,k=i<<1; j<MAX; j+=k)
            {
				set(j);
            }
        }
	}
    primes[(j=0)++] = 2;
    primemap[2]=1;
	for(i=3; i<MAX; i+=2)
    {
		if(!chk(i))
        {
			primes[j++] = i;
            primemap[i]=j;
        }
	}
    primelen = j;
}

int main()
{
	unsigned n,t;
	sieve();
    //printf("the largest prime found is %d\n", primes[primelen-1]);
    scanf("%d", &t);
	while(t--)
	{
        scanf("%d", &n);
        if(primemap.find(n)!=primemap.end())
        {
            int row = (1+sqrt(8*(primemap[n]-1)+1))/2;
            int col = primemap[n] - row*(row-1)/2;
            //printf("%d is the %dth prime\n", n, primemap[n]);
            //printf("row = %d, col = %d\n", row, col);
            printf("%d %d\n", row, col);
        }
        else
            printf("-1\n");
	}
	return 0;
}
