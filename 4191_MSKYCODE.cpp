/*
TASK: MSKYCODE
ALGO: inclusion exclusion
*/

#include <cstdio>
#include <string.h>

template< class T > void setmax(T &a, T b) { if(a < b) a = b; }

#define CLR(p) memset(p, 0, sizeof(p))

const int MAX = 10000;
const int LEN = 1230;

int primes[LEN], total;
int flag[(MAX+64)>>6];
int cnt[MAX+1], maxval;
unsigned long long nc4[MAX+1];

#define cp(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define sp(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() 
{
	int i, j, k;
	primes[0] = 2, total = 1;
	for(i = 3; i < MAX; i+=2) 
    {
		if(!cp(i)) 
        {
			primes[total++] = i;
			k = i << 1;
			for(j = i * i; j < MAX; j += k) 
                sp(j);
		}
	}
}

void init() 
{
	nc4[4] = 1;
	for(int i = 5; i <= MAX; i++) 
        nc4[i] = (nc4[i-1]*i)/(i-4);
}

unsigned long long solve(int num, int idx) 
{
	unsigned long long res;
	int i, present = 0, next;
	for(i = num; i <= maxval; i += num)
        present += cnt[i];
	res = nc4[present];
	if(present >= 4) 
    {
		for(i = idx; i < total; i++) 
        {
			next = num * primes[i];
			if(next > (maxval >> 2)) 
                break;
			res -= solve(next, i + 1);
		}
	}
	return res;
}

int main() 
{
	int n, a, i;
	sieve();
	init();
	while(scanf("%d", &n)==1) 
    {
		CLR(cnt);
		maxval = 0;
		for(i = 0; i < n; i++) 
        {
			scanf("%d", &a);
			setmax(maxval, a);
			cnt[a]++;
		}
		printf("%lld\n", solve(1, 0));
	}
	return 0;
}
