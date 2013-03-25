/*
6830. Soccer Bets
Input:
1
ITA URU 2 0
ITA IRE 1 0
ITA ARG 3 4
YUG ARG 2 3
GER CZE 1 0
ENG GER 3 4
ITA ENG 2 1
CAM COL 2 1
ENG CAM 3 2
ENG BEL 1 0
GER ARG 1 0
CZE CRC 4 1
NET GER 1 2
BRZ ARG 0 1
SPA YUG 1 2
ROM IRE 4 5

Output:
GER
 */
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
//#include <pair>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char first[4], second[4];
		int f_n, s_n;
		map<string,int> wins;
		for(int i=0;i<16;i++)
		{
			scanf("%s %s %d %d", first, second, &f_n, &s_n);
			//cout<<"first = "<<first<<", second = "<<second<<", f_n = "<<f_n<<", s_n = "<<s_n<<endl;
			map<string,int>::iterator s_t;
			if(f_n>s_n)
			{
				s_t=wins.find(string(first));
				if(s_t==wins.end())
				{
					wins.insert(std::pair<string,int>(first,1));
				}
				else
				{
					s_t->second++;
				}
			}
			else
			{
				s_t=wins.find(string(second));
				if(s_t==wins.end())
				{
					wins.insert(std::pair<string,int>(second,1));
				}
				else
				{
					s_t->second++;
				}
			}
		}
		map<string,int>::iterator it;
		for (it=wins.begin(); it!=wins.end(); ++it)
		{
			//printf("%s %d\n", it->first.c_str(),it->second);
			//cout<<it->first<<", "<<it->second<<endl;
			if(it->second==4)
			{
				cout<<it->first<<endl;
				break;
			}
		}
	}
	return 0;
} 