//
//  1874_BWHEELER.cpp
//
//
//  Created by Haijun Deng on 13-6-4.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Burrows Wheeler Precompression
 ALGO: sort
 Sample Input:
 2
 bacab
 3
 rwlb
 11
 baaabaaaabbbaba
 0
 Sample Output:
 abcba
 rbwl
 baaabbbbaaaaaab
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1024;

char sorted[MAX], str[MAX], num[8];
int cnt[26], next[MAX];

void countingSort(char *p, char *s, int &len)
{
	int i; len = 0;
	memset(cnt,0,sizeof(cnt));
	for(i = 0; p[i]>='a'; i++)
        cnt[p[i]-'a']++;
	for(i = 0; i < 26; i++)
		while(cnt[i]--)
			s[len++] = i + 'a';
	s[len] = 0;
}

int main()
{
	int k, len, i, j;
	while(k=atoi(fgets(num, 8, stdin)))
	{
		fgets(str, MAX, stdin);
		countingSort(str, sorted, len);
		for(i = 0; i < len; i++)
		{
			if(!i || sorted[i]!=sorted[i-1])
				j = 0;
			else
				j++;
			while(sorted[i]!=str[j])
				j++;
			next[i] = j;
		}
		for(i = 0, k = next[k-1]; i < len; i++, k = next[k])
			putchar(str[k]);
		putchar('\n');
	}
	return 0;
}
