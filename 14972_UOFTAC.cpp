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
		int s_w=0, s_h=0, t_n=0;
		vector<char> steps(s);
		for(int i=0; i<s; i++)
		{
			cin>>steps[i];
			switch(steps[i])
			{
				case D:
					s_h++;
					break;
				case L:
					if(s_w)
						s_w--;
					break;
				case R:
					if(s_w<w-1)
						s_w++;
					break;
			}
			switch(underground[s_h][s_w])
			{
				case D:
					s_h++;
					break;
				case L:
					if(s_w)
						s_w--;
					break;
				case R:
			
			}
		}
	}
	return 0;
}
