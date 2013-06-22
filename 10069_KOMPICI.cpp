/*
TASK: Kompići
Input:
3
4
20
44
Output:
1
*/
#include <stdio.h>
#include <string.h>
//#include <vector>

using namespace std;
typedef long long LL;

int n;
int cnt[1500];
char st[20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%s", st);
		int len = strlen(st);
		int state = 0;
		for (int j = 0; j < len; j++)
			state |= (1 << (st[j] - '0'));
		cnt[state]++;
	}
	LL ret = 0;
	for (int i = 0; i < (1 << 10); i++)
		for (int j = 0; j < (1 << 10); j++)
			if (i != j && (i & j)) 
			{
				ret += (LL)cnt[i] * cnt[j];
			}
	for (int i = 0; i < (1 << 10); i++)
		ret += cnt[i] * (cnt[i] - 1);
	printf("%lld\n",ret/2);
	return 0;
}
