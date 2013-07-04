/*
TASK: Johnny The Gambler
Sample Input
1
10 3 1 5 9
Sample Output
1. 1
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int cnt[1000005];
int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("%d. ", cas);
		int x, n, a;
		scanf("%d%d", &x, &n);
		LL ret = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (x - a >= 0) {
				ret += (LL)cnt[x - a];
			}
			cnt[a]++;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
