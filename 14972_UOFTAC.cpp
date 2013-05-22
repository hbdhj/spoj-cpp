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
			switch(steps[i])
			{
				case D:
					if((s_h+1)<h) //Not the bottom
					{
						switch(underground[s_h+1][s_w])
						{
							case T:
								t_n++;
								s_h++;
								break;
							case S:
								break;
							case D:
								s_h++;
								break;	
							case E:
								while((s_h+1)<h)
								{
									if(underground[s_h+1][s_w]!='E')
										break;
									else
										s_h++;
								}
								break;	
						}
					}
					break;
				case L:
					if(s_h>=0) //Not the bottom
					{
						switch(underground[s_h][s_w-1])
						{
							case T:
								t_n++;
								s_w--;
								break;
							case S:
								break;
							case D:
								s_w--;
								break;	
							case E:
								s_w--;
								while((s_h+1)<h)
								{
									if(underground[s_h][s_w]!='E')
										break;
									else
										s_h++;
								}
								break;	
						}
					}
					else if(s_w)
						s_w--;
					break;
				case R:
					if(s_h>=0) //Not the bottom
					{
						
					}
					else if(s_w<w-1)
						s_w++;
					break;
			}
			
		}
	}
	return 0;
}
