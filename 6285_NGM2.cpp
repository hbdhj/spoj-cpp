/*
TASK: Another Game With Numbers
ALGO: inclusion exclusion
*/

#include <iostream>
using namespace std;

template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }

const int MAX = 16;

int main() 
{
	int i, j, k, tot, nb;
	unsigned long long d, val, n, a[MAX];
	cin >> n >> k;
	for(i = 0; i < k; i++) 
        cin >> a[i];
	tot = (1 << k), d = n;
	for(i = 1; i < tot; i++) 
    {
		nb = 0, val = 1;
		for(j=0; j < k; j++) 
        {
			if(i & (1<<j))
            {
				nb++;
				val = lcm(val, a[j]);
			}
		}
		if(nb & 1) 
            n -= d / val;
		else 
            n += d / val;
	}
	printf("%lld\n", n);
	return 0;
}
