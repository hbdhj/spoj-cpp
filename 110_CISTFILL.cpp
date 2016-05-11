//
//  110_CISTFILL.cpp
//  
//
//  Created by Haijun Deng on 13-5-2.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Fill the Cisterns
 ALGO: binary search
 Sample input:
 3 
 2 
 0 1 1 1 
 2 1 1 1 
 1 
 4 
 11 7 5 1 
 15 6 2 2 
 5 8 5 1 
 19 4 8 1 
 132 
 4 
 11 7 5 1 
 15 6 2 2 
 5 8 5 1 
 19 4 8 1 
 78 
 
 Sample output:
 1.00 
 OVERFLOW 
 17.00 
 */

#include <ios>
#include <algorithm>
using namespace std;

const int MAX = 50005, LVL = 32;
const double INF = 2000000000, EPS = 1e-9;
struct cist { double h0, h1, l, w; } C[MAX];

double area(double low, double high, int n) 
{
	double ret = 0.0, h0, h1;
	for(int i=0; i < n; i++) 
    {
		h0 = max(C[i].h0, low);
		h1 = min(C[i].h1, high);
		if(h0+EPS < h1) 
            ret += (h1-h0)*C[i].l*C[i].w;
	}
	return ret;
}

double find_res(double low, double high, double vol, int n)
{
	int cnt = LVL;
	double mid, start = low;
	while(cnt--) 
    {
		mid = (high + low)/2.0;
		if(area(start, mid, n)+EPS < vol) 
            low = mid;
		else 
            high = mid;
	}
	return low;
}

int main() {
	int t, n, i;
	double hb, h, l, w, v, low, high, res;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d", &n);
		low = INF, high = -INF;
		for(i=0; i<n; i++) 
        {
			scanf("%lf%lf%lf%lf", &hb, &h, &w, &l);
			C[i].h0 = hb, C[i].h1 = hb+h;
			C[i].w = w, C[i].l = l;
			low = min(low, hb);
			high = max(high, hb+h);
		}
		scanf("%lf", &v);
		if(area(low, high, n)+EPS < v) 
            printf("OVERFLOW\n");
		else 
        {
			res = find_res(low, high, v, n);
			printf("%.2lf\n", res + EPS);
		}
	}
	return 0;
}
