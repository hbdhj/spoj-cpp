//
//  7975.cpp
//  
//
//  Created by Haijun Deng on 13-1-13.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
4
13 7 5
7 13 6
14 3 12
15 6 16
2
-1 -1 -1
-1 -1 -1
4
-1 -2 -3
-4 -5 -6
-1 -2 -3
-7 -6 -5
0
 Output:
1. 22
2. -3
3. -32

 */
#include <stdio.h>

const int inf = 0x7f7f7f7f;
int tri[100000][3];

inline int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n, i, j, a, b, c, d, cs = 1;
	while(scanf("%d", &n)==1 && n) {
		for(i = 0; i < n; i++)
			for(j = 0; j < 3; j++)
				scanf("%d", &tri[i][j]);
		tri[0][0] = inf;
		tri[0][2] += tri[0][1];
		for(i = 1; i < n; i++) {
			for(j = 0; j < 3; j++) {
				a = (j==2)? inf : tri[i-1][j+1];
				b = tri[i-1][j];
				c = (j==0)? inf : tri[i-1][j-1];
				d = (j==0)? inf : tri[i][j-1];
				tri[i][j] += min(min(a, b), min(c, d));
			}
		}
		printf("%d. %d\n", cs++, tri[n-1][1]);
	}
	return 0;
}
