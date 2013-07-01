/*
TASK: Build the Fence
ALGO: convex hull
 Input:
 8
 
 5
 0 0
 0 5
 10 5
 3 3
 10 0
 
 1
 0 0
 
 3
 0 0
 1 0
 2 0
 
 4
 0 0
 0 0
 0 1
 1 0
 
 3
 0 0
 0 1
 1 0
 
 6
 0 0
 -1 -1
 1 1
 2 2
 3 3
 4 4
 
 2
 10 0
 0 0
 
 7
 -3 -4
 2 -3
 4 3
 -4 2
 0 5
 2 -3
 -1 4
 
 Output:
 30.00
 1 5 3 2
 
 0.00
 1
 
 4.00
 1 3
 
 3.41
 1 4 3
 
 3.41
 1 3 2
 
 14.14
 2 6
 
 20.00
 2 1
 
 26.98
 1 2 3 5 4
*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 100032;
const double EPS = 1e-10;

struct point {
	int x, y, id;
};

point P[MAX], C[MAX], P0;

inline int triArea2(const point &a, const point &b, const point &c)
{
	return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline int sqDist(const point &a, const point &b) 
{
	return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline double dist(const point &a, const point &b) 
{
	return hypot((double)(a.x-b.x), (double)(a.y-b.y));
}

inline bool comp(const point &a, const point &b) 
{
	int d = triArea2(P0, a, b);
	if(d < 0) 
        return false;
	if(!d && sqDist(P0, a) > sqDist(P0, b)) 
        return false;
	return true;
}

inline bool normal(const point &a, const point &b) 
{
	return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b)
{
	return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np) 
{
	sort(P, P+np, normal);
	np = unique(P, P+np, issame) - P;
}

void convexHull(int &np, int &nc) 
{
	int i, j, pos = 0;
	for(i = 1; i < np; i++)
		if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
			pos = i;
	swap(P[0], P[pos]);
	P0 = P[0];
	sort(&P[1], &P[np], comp);
	for(i = 0; i < 3; i++)
        C[i] = P[i];
	for(i = j = 3; i < np; i++) 
    {
		while(triArea2(C[j-2], C[j-1], P[i]) < 0) 
            j--;
		C[j++] = P[i];
	}
	nc = j;
}

void compress(int &nc) 
{
	int i, j, d;
	for(i=j=1; i < nc; i++) 
    {
		d = triArea2(C[j-1], C[i], C[i+1]);
		if(d || (!d && C[j-1].id == C[i+1].id)) 
            C[j++] = C[i];
	}
	nc = j;
}

int main() 
{
	int i, np, nc, t;
	double perim;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d", &np);
		for(i = 0; i < np; i++) 
        {
			scanf("%d%d", &P[i].x, &P[i].y);
			P[i].id = i + 1;
		}
		makeUnique(np);
		if(np==1) 
        {
			printf("0.00\n");
			printf("%d\n", P[0].id);
		}
		else if(np==2) 
        {
			perim = 2.0 * dist(P[0], P[1]);
			printf("%.2lf\n", perim + EPS);
			printf("%d %d\n", P[0].id, P[1].id);
		}
		else 
        {
			convexHull(np, nc);
			C[nc] = C[0];
			perim = 0.00;
			for(i = 0; i < nc; i++) 
                perim += dist(C[i], C[i+1]);
			printf("%.2lf\n", perim + EPS);
			compress(nc);
			printf("%d", C[0].id);
			for(i = 1; i < nc; i++)
                printf(" %d", C[i].id);
			printf("\n");
		}
		if(t) 
            printf("\n");
	}
	return 0;
}
