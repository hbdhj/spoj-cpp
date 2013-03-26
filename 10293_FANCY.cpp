#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int tN;
	scanf("%d", &tN);
	if(tN>0)
	{
		vector<string> input;
		for(int i=0;i<tN;i++)
		{
			char str[30];
			scanf("%s", str);
			input.push_back(str);
		}
		for(int i=0;i<tN;i++)
		{
			int ret = 1;
			for(int j=0;j<input[i].size()-1;j++)
				if(input[i][j]==input[i][j+1])
					ret*=2;
			printf("%d\n", ret);
		}
	}
	return 0;
}