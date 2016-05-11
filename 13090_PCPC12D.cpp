/*
TASK: New Strategy
ALGO: sort
*/
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1024;
const int LEN = 256;

char str[MAX][LEN];
int cnt[MAX][26];
int idx[MAX];

bool comp(int i, int j)
{
	for(int k = 0; k < 26; k++) {
		if(cnt[i][k] > cnt[j][k])
            return true;
		if(cnt[i][k] < cnt[j][k])
            return false;
	}
	return i<j;
}

int main()
{
	int test, n, i, j, cs;
	char buff[2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++)
    {
		scanf("%d", &n);
		gets(str[0]);
		for(i = 0; i < n; i++)
        {
			gets(str[i]);
			idx[i] = i;
			memset(cnt[i],0,sizeof(cnt[i]));
			for(j = 0; str[i][j]; j++)
            {
				if(isalpha(str[i][j]))
                {
					cnt[i][tolower(str[i][j])-'a']++;
				}
			}
		}
		sort(idx, idx + n, comp);
		printf("case: %d\n", cs);
		for(i = 0; i < n; i++)
        {
			printf("%s\n", str[idx[i]]);
		}
	}
	return 0;
}
