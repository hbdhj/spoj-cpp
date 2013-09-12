/*
TASK: Zig-Zag rabbit
ALGO: math
*/

#include <cstdio>

using namespace std;

const int LEN = 300003;
char buff[LEN];

inline long long getlevel(long long p, long long n) 
{
	if(p <= n) 
        return ((p+1) * p) >> 1;
	p = n + n - p - 1;
	return n * n - ((p * (p+1)) >> 1);
}

inline long long getval(long long x, long long y, long long n) 
{
	long long en, p = x + y - 1;
	en = getlevel(p, n);
	if(p > n) 
        x -= p - n, y -= p - n;
	if(p&1) 
        return en - x + 1;
	else 
        return en - y + 1;
}

int main() 
{
	int i, n, len, r, c;
	long long total;
	scanf("%d%d%s", &n, &len, buff);
	for(i=0, total=r=c=1; i < len; i++) 
    {
		switch(buff[i]) 
        {
			case 'U': 
                total += getval(--r, c, n); 
                break;
			case 'D': 
                total += getval(++r, c, n); 
                break;
			case 'L': 
                total += getval(r, --c, n); 
                break;
			case 'R': 
                total += getval(r, ++c, n); 
                break;
		}
	}
	printf("%lld\n", total);
	return 0;
}
