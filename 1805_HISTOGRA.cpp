/*
TASK: Largest Rectangle in a Histogram
ALGO: stack
input
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
output
8
4000
*/
#include <iostream>

template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }

#define i64 long long

const int MAX = 100009;

i64 calc(int *ht, int n) 
{
	i64 ret = 0;
	int top = 1, st[MAX], i;
	ht[0] = st[0] = ht[++n] = 0;
	for(i = 1; i <= n; i++) 
    {
		while(top > 1 && ht[st[top-1]] >= ht[i]) 
        {
			ret = _max(ret, (i64)ht[st[top-1]]*(i64)(i - st[top-2]-1));
			top--;
		}
		st[top++] = i;
	}
	return ret;
}

int main() {
	int n, i, ht[MAX];
	while(scanf("%d", &n)==1 && n) 
    {
		for(i = 1; i <= n; i++) 
            scanf("%d", &ht[i]);
		printf("%lld\n", calc(ht, n));
	}
	return 0;
}
