/*
TASK: Foxhole
Input:
2
2 3 4
DDD
TES
R
D
R
L
3 2 6
TE
TE
ET
R
R
L
R
L
R

Output:
1
2

*/

#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h, w, s;
		cin>>h>>w>>s;
		vector<string> underground(h);
		for(int i=0; i<h; i++)
		{
			cin>>underground[i];
		}
		int s_w=0, s_h=-1, t_n=0;
		vector<char> steps(s);
		for(int i=0; i<s; i++)
		{
			cin>>steps[i];
			//printf("s_h = %d, s_w = %d before the step %d - %c, t_n = %d\n", s_h, s_w, i+1, steps[i], t_n);
			switch(steps[i])
			{
				case 'D':
					if((s_h+1)<h) //Not the bottom
					{
						switch(underground[s_h+1][s_w])
						{
							case 'T':
								t_n++;
								s_h++;
								underground[s_h][s_w]='D';
								break;
							case 'S':
								break;
							case 'D':
							case 'E':
								s_h++;
								break;	
						}
					}
					break;
				case 'L':
					if(s_h>=0&&s_w) //Not the bottom
					{
						switch(underground[s_h][s_w-1])
						{
							case 'T':
								t_n++;
								s_w--;
								underground[s_h][s_w]='D';
								break;
							case 'S':
								break;
							case 'D':
							case 'E':
								s_w--;
								break;	
                        }
					}
					else if(s_w)
						s_w--;
					break;
				case 'R':
					if(s_h>=0&&s_w<w-1) //Not the bottom
					{
						switch(underground[s_h][s_w+1])
						{
							case 'T':
								t_n++;
								s_w++;
								underground[s_h][s_w]='D';
								break;
							case 'S':
								break;
							case 'D':
							case 'E':
								s_w++;
								break;	
						}
					}
					else if(s_w<w-1)
						s_w++;
					break;
			}
			//fall down
			while((s_h<h-1)&&(underground[s_h+1][s_w]=='E'))
				s_h++;
			//printf("s_h = %d, s_w = %d after the step %d - %c, t_n = %d\n", s_h, s_w, i+1, steps[i], t_n);
		}
		printf("%d\n",t_n);
	}
	return 0;
}

