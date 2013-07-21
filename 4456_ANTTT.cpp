/*
TASK: ANTTT
ALGO: geometry
*/

#include <cstdio>
#include <algorithm>

using namespace std;

template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

const int MAX = 1024;

struct Point { int x, y; };
struct Segment { Point a, b; };

Segment seg[MAX];
int root[MAX];

int find(int u) 
{
	if(u!=root[u]) 
        root[u] = find(root[u]);
	return root[u];
}

inline void link(int u, int v)
{
	root[u] = root[v];
}

inline int direction(Point &pi, Point &pj, Point &pk) 
{
	return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

inline bool onsegment(Point &pi, Point &pj, Point &pk) 
{
	return (inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) 
{
	int d1, d2, d3, d4;
	d1 = direction(p3, p4, p1);
	d2 = direction(p3, p4, p2);
	d3 = direction(p1, p2, p3);
	d4 = direction(p1, p2, p4);
	if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
	if(!d1 && onsegment(p3, p4, p1)) 
        return true;
	if(!d2 && onsegment(p3, p4, p2)) 
        return true;
	if(!d3 && onsegment(p1, p2, p3)) 
        return true;
	if(!d4 && onsegment(p1, p2, p4)) 
        return true;
	return false;
}

int main() 
{
	int t, m, n, i, j, u, v;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++) 
        {
			root[i] = i;
			scanf("%d%d%d%d", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
		}
		for(i = 1; i <= n; i++) 
        {
			for(j = 1; j <= n; j++) 
            {
				u = find(i);
				v = find(j);
				if(u != v && intersect(seg[i].a, seg[i].b, seg[j].a, seg[j].b)) link(u, v);
			}
		}
		while(m--) 
        {
			scanf("%d%d", &i, &j);
			u = find(i);
			v = find(j);
			if(u==v) 
                printf("YES\n");
			else 
                printf("NO\n");
		}
	}
	return 0;
}
