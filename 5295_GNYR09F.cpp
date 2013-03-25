//
//  5295_GNYR09F.cpp
//  
//
//  Created by Haijun Deng on 13-3-25.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: dynamic programming
 Input:
 10
 1 5 2
 2 20 8
 3 30 17
 4 40 24
 5 50 37
 6 60 52
 7 70 59
 8 80 73
 9 90 84
 10 100 90
 Output:
 1 6
 2 63426
 3 1861225
 4 168212501
 5 44874764
 6 160916
 7 22937308
 8 99167
 9 15476
 10 23076518
 */
#include <iostream>
#include <string.h>

using namespace std;

#define memo(a,v) memset(a,v,sizeof(a))
#define i64 long long
#define u64 unsigned i64

int N, K;
i64 dp[ 110 ][ 110 ][ 2 ];

i64 cal( int pos, int total, int prev )
{
	if( total < 0 ) return 0;
	if( pos < 0 )
    {
		if( total == 0 ) 
            return 1;
		return 0;
	}
	i64 &ret = dp[ pos ][ total ][ prev ];
	if( ret != -1 ) return ret;
	ret = 0;
	if( prev == 1 )
    {
		ret += cal(pos - 1, total - 1, 1 );
		ret += cal(pos - 1, total, 0 );
	}
	else
	{
		ret += cal(pos - 1, total, 1 );
		ret += cal(pos - 1, total, 0 );
	}
	return ret;
}
int main()
{
	int tc;
	memo(dp,-1);
	cin >> tc;
	while( tc -- )
	{
        
		int cs;
		cin >> cs >> N >> K;
		cout << cs<<" ";
		i64 ret = cal(N - 2,K,0) ;
		ret += cal(N - 2,K,1);
		cout << ret << endl	;
	}
	return 0;
}