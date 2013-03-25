/*
339. Recursive Sequence
Input:
3 
3 
5 8 2 
32 54 6 
2 
3 
1 2 3 
4 5 6 
6 
3 
24 354 6 
56 57 465 
98765432

Output:
8 
714 
257599514
`*/
#include <iostream>
#include <cstring>

#define CPY(d, s) memcpy(d, s, sizeof(s))
#define i64 long long

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 11, MOD = 1000000000;

int mat[MAX][MAX], m[MAX][MAX], a[MAX];

void multi(int x[MAX][MAX], int y[MAX][MAX], int n) 
{
	int r[MAX][MAX] = {0}, i, j, k;
	i64 temp;
	for(i = 1; i <= n; i++) 
    {
		for(j = 1; j <= n; j++) 
        {
			for(k = 1; k <= n; k++) 
            {
				temp = x[i][k];
				temp *= y[k][j];
				temp += r[i][j];
				temp %= MOD;
				r[i][j] = temp;
			}
		}
	}
	CPY(x, r);
}

void expo(int p, int n) 
{
	if(!p) 
    {
		for(int i = 1; i <= n; i++) 
        {
			for(int j = 1; j <= n; j++) m[i][j] = 0;
			m[i][i] = 1;
		}
	}
	else if(p & 1) 
    {
		expo(p-1, n);
		multi(m, mat, n);
	}
	else 
    {
		expo(p >> 1, n);
		multi(m, m, n);
	}
}

int main() {
	int t, i, j, k, n;
	i64 sum, temp;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d", &k);
		for(i = k; i; i--) 
            scanf("%d", &a[i]);
		for(j = 1; j <= k; j++) 
            scanf("%d", &mat[1][j]);
		scanf("%d", &n);
		if(n <= k) 
            printf("%d\n", a[k-n+1] % MOD);
		else 
        {
			for(i = 2; i <= k; i++) 
            {
				for(j = 1; j <= k; j++) 
                    mat[i][j] = 0;
				mat[i][i-1] = 1;
			}
			expo(n-k, k);
			sum = 0;
			for(i = 1; i <= k; i++) 
            {
				temp = m[1][i];
				temp *= a[i];
				sum += temp;
				sum %= MOD;
			}
			printf("%d\n", (int)sum);
		}
	}
	return 0;
}