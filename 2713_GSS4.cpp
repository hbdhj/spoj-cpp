/*
TASK: Can you answer these queries IV
ALGO: binary indexed tree
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define i64 long long
#define CLR(p) memset(p, 0, sizeof(p))

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 100001;

i64 BIT[MAX];
i64 a[MAX];
int root[MAX];

void update(int x, i64 v, int n) 
{
	while(x <= n) 
    {
		BIT[x] += v;
		x += (x & -x);
	}
}

i64 readsum(int x) 
{
	i64 ret = 0;
	while(x > 0)
    {
		ret += BIT[x];
		x -= (x & -x);
	}
	return ret;
}

int find(int u) 
{
	if(u != root[u]) 
        root[u] = find(root[u]);
	return root[u];
}

void modify(int x, int y, int n)
{
	int i = find(x);
	while(x <= i && i <= y) 
    {
		if(a[i] != 1) 
        {
			update(i, -a[i], n);
			a[i] = (i64)floor(sqrt((double)a[i]));
			update(i, a[i], n);
			if(a[i] == 1) 
                root[i] = i + 1;
		}
		i = find(i + 1);
	}
}

int main() 
{
	int n, q, i, x, y, t, cs;
	for(cs = 1; scanf("%d", &n) == 1; cs++) 
    {
		CLR(BIT);
		for(i = 1; i <= n; i++) 
        {
			scanf("%lld", a + i);
			update(i, a[i], n);
			root[i] = i;
            /*for (int l=0; l<=n; l++) 
            {
                printf("a[%d] = %lld, BIT[%d] = %lld, root[%d] = %d\n", l, a[l], l, BIT[l], l, root[l]);
            }*/
		}
        printf("Case #%d:\n", cs);
		scanf("%d", &q);
		while(q--) 
        {
			scanf("%d %d %d", &t, &x, &y);
			if(x > y) 
                swap(x, y);
			if(t) 
                printf("%lld\n", readsum(y) - readsum(x-1));
			else 
                modify(x, y, n);
            /*for (int l=0; l<=n; l++) 
            {
                printf("a[%d] = %lld, BIT[%d] = %lld, root[%d] = %d\n", l, a[l], l, BIT[l], l, root[l]);
            }*/
            
		}
		printf("\n");
	}
	return 0;
}