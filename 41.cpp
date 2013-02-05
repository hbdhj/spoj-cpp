/*
41. Play on Words
Sample input:
3
2
acm
ibm
3
acm
malform
mouse
2
ok
ok
Sample output:
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
*/

#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	int i,j,t;
	scanf("%d",&t);
	vector<int> wordNum(t,0);
	vector<int> rets(t,0);
	for(i=0;i<t;i++)
	{
		scanf("%d",&wordNum[i]);
		vector<int> starts(26,0);
		vector<int> ends(26,0);
		for(j=0;j<wordNum[i];j++)
		{
			char word[1000];
			scanf("%s", word);
			starts[word[0]-'a']++;
			ends[word[strlen(word)-1]-'a']++;
			//words.push_back(string(word));
		}
		for(j=0;j<26;j++)
		{
			if(starts[j]!=ends[j])
			{
				rets[i]+=starts[j];
				rets[i]+=ends[j];
			}
		}
	}
	for(i=0;i<t;i++)
	{
		if(rets[i]>2)
			printf("The door cannot be opened.\n");
		else
			printf("Ordering is possible.\n");	
	}
	return 0;
}