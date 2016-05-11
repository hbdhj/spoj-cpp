//
//  10239_ACPC11B.cpp
//  
//
//  Created by Haijun Deng on 13-5-18.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Between the Mountains
 ALGO: binary search
 Input:
 2
 8 1 3 5 7 9 7 3 1
 8 2 4 6 8 10 8 6 2
 8 2 3 5 10 9 3 2 1
 7 1 2 6 12 13 3 2
 
 Output:
 1
 0
 */
#include <iostream>
#include <algorithm>

using namespace std;

template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
#define MX 1000009
const int INF = 0x7f7f7f7f;
int a[MX], b[MX];

int main() 
{
	int i,j,n,m,res,tmp,cs;
	cin>>cs;
	while(cs--)
    {
	    cin>>n;
	    for(i=0;i<n;i++)
            cin>>a[i];
	    sort(a,a+n);
        
	    cin>>m;
	    for(i=0;i<m;i++)
            cin>>b[i];
	    sort(b,b+m);
	    b[m] = INF;
	    res=INF;
	    for(i=0;i<n;i++)
        {
	        j=lower_bound(b,b+m,a[i])-b;
	        tmp=_abs(b[j]-a[i]);
	        res=_min(tmp,res);
	        if(j-1>=0)
            {
	            tmp=_abs(b[j-1]-a[i]);
                res=_min(tmp,res);
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}

