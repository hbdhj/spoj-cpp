/*
TASK: Kind and gently
ALGO: sort
 INPUT
 3
 5 1 1 3
 6 2
 5 10
 4 20
 3 15
 1 1
 3 1 0 5
 3 15
 2 20
 1 60
 2 1 1 25
 15 10
 12 10

 OUTPUT
 Scenario #1: 19
 Scenario #2: 15
 Scenario #3: 145
*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct Wood { int h, c; };

Wood wood[100000];

inline bool comp(const Wood &a, const Wood &b)
{
	return a.h != b.h ? a.h > b.h : a.c > b.c;
}

int main()
{
	int test, cs, e, w, i, k, total, cnt, tmp, hi, wi, h, m;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++)
    {
		scanf("%d %d %d %d", &e, &m, &h, &w);
		for(i = k = 0; i < e; i++)
        {
			scanf("%d %d", &hi, &wi);
			if(wi / (1 + m) > 0)
            {
				wood[k].h = hi, wood[k].c = wi / (1 + m);
				k++;
			}
		}
		sort(wood, wood + k, comp);
		for(total = i = cnt = 0; i < k && cnt < w; i++)
        {
			tmp = min(wood[i].c, w - cnt);
			cnt += tmp;
			total += wood[i].h * tmp;
		}
		total += cnt * h;
		printf("Scenario #%d: %d\n", cs, total);
	}
	return 0;
}
