//
//  5971_LCMSUM.cpp
//
//
//  Created by Haijun Deng on 13-5-23.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: LCM Sum
 ALGO: math
 Sample Input :
 3
 1
 2
 5

 Sample Output :
 1
 4
 55
 */

#include <cstdio>
using namespace std;

#define MAX 1000000
#define LMT 1000
//#define MAX 100
//#define LMT 10

int pfactor[MAX+10];
long long int mcount[MAX+10], mval[MAX+10];

int main()
{
	mval[1] = mcount[1] = 1;
	for(int i=1; i<=MAX; i++)
        pfactor[i] = i;
	for(int i=2; i<=LMT; i++)
		if(pfactor[i]==i)
			for(int j=i<<1; j<=MAX; j+=i)
				if(pfactor[j]==j)
					pfactor[j] = i;
    /*printf("pfactor = ");
    for(int i=0; i<LMT+10; i++)
    {
        printf(" %d", pfactor[i]);
    }
	printf("\n");*/
    for(int i=2, k; i<=MAX; i++)
	{
		k = i;
		mcount[i] = 1;
		while(k%pfactor[i]==0)
		{
			mcount[i] *= pfactor[i];
			k /= pfactor[i];
		}
	}
	/*printf("mcount = ");
    for(int i=0; i<LMT+10; i++)
    {
        printf(" %lld", mcount[i]);
    }
	printf("\n");*/
    for(int i=2; i<=MAX; i++)
		mval[i] = mval[i/pfactor[i]]+mcount[i]*(mcount[i]-mcount[i]/pfactor[i])*mval[i/mcount[i]];
	/*printf("mval = ");
    for(int i=0; i<LMT+10; i++)
    {
        printf(" %lld", mval[i]);
    }
	printf("\n");*/
    int t, n;
	long long res;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		res = mval[n]-1;
		if(res&1)
            res *= (n>>1);
		else
            res>>=1, res*=n;
		res += n;
		printf("%lld\n", res);
	}
	return 0;
}
