//
//  22_TRICENTER.cpp
//  
//
//  Created by Haijun Deng on 13-5-25.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

/*
TASK: Triangle From Centroid
ALGO: geometry
 Input:
 2
 3.0 0.8660254038 0.8660254038 0.8660254038
 657.8256599140 151.6154399062 213.5392629932 139.4878846649
 
 Output:
 3.897 0.000
 149604.790 150.275
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	double a, b, c, da, db, dc, s, r, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf", &a, &da, &db, &dc);
		s = 3.0*a*da/2.0;
		b = 2.0*s/3.0/db;
		c = 2.0*s/3.0/dc;
		r = a*b*c/4.0/s;
		m = 4.0*(r*r-(a*a+b*b+c*c)/9.0);
		m = (m<0.0) ? 0.0 : m;
		printf("%.3lf %.3lf\n", s, sqrt(m));
	}
	return 0;
}