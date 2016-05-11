//
//  7185.cpp
//
//
//  Created by Haijun Deng on 13-2-6.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 7185. Bye Bye Cakes
 Input:
 2 3 4 5 1 1 1 1
 3 6 9 0 1 2 3 4
 -1 -1 -1 -1 -1 -1 -1 -1
 Output:
 3 2 1 0
 0 0 0 12
 */
#include <stdio.h>

int main() {
	int a, b, c, d, aa, bb, cc, dd, at, bt, ct, dt, mx;
	while(scanf("%d%d%d%d%d%d%d%d",&a, &b, &c, &d, &aa, &bb, &cc, &dd)==8 && a>=0) {
		at = (a + aa - 1) / aa;
		bt = (b + bb - 1) / bb;
		ct = (c + cc - 1) / cc;
		dt = (d + dd - 1) / dd;
		mx = at;
		mx = mx>bt? mx:bt;
		mx = mx>ct? mx:ct;
		mx = mx>dt? mx:dt;
		printf("%d %d %d %d\n", aa*mx-a, bb*mx-b, cc*mx-c, dd*mx-d);
	}
	return 0;
}
