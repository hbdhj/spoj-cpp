/*
TASK: Nested Dolls
ALGO: sorting, greedy
 SAMPLE INPUT
 4
 3
 20 30 40 50 30 40
 4
 20 30 10 10 30 20 40 50
 3
 10 30 20 20 30 10
 4
 10 10 20 30 40 50 39 51    
 SAMPLE OUTPUT
 1
 2
 3
 2  
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 20000;

typedef struct { int ff, ss; } pii;

inline bool scomp(const pii &a, const pii &b) 
{
    return a.ss != b.ss ? a.ss > b.ss : a.ff < b.ff;
}

inline bool bcomp(const pii &a, const pii &b)
{
    return a.ff < b.ff;
}

int main() 
{
    int test, i, j, k, n, ans;
    pii p[MAX];
    scanf("%d", &test);
    while(test--) 
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++) 
            scanf("%d %d", &p[i].ff, &p[i].ss);
        sort(p, p + n, scomp);
        for(i = j = 0, ans = n; i < n; i++) 
        {
            k = upper_bound(p, p+j, p[i], bcomp) - p;
            if(k == j) 
                p[j++] = p[i];
            else
            {
                ans--;
                p[k].ff = p[i].ff;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
