//
//  726_PRO.cpp
//
//
//  Created by Haijun Deng on 13-4-2.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: simulation
 Input:
 5
 3 1 2 3
 2 1 1
 4 10 5 5 1
 0
 1 2

 Output:
 19
 */
#include <set>
#include <ios>
using namespace std;

#define i64 long long
#define FS "%lld\n"

multiset< int > S;
multiset< int > :: iterator fwd, rev;

int main()
{
	i64 sum = 0;
	int n, i, j, p,m;
	scanf("%d", &n);
	for(i=0; i<n; i++)
    {
		scanf("%d", &m);
		for(j=0; j<m; j++)
        {
			scanf("%d", &p);
			S.insert(p);
		}
		fwd = S.begin();
		rev = S.end();
        rev--;
		sum += (*rev - *fwd);
		S.erase(fwd);
		S.erase(rev);
	}
	printf(FS, sum);
	return 0;
}
