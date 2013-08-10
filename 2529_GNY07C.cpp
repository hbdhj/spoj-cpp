/*
TASK: Model Rocket Height
ALGO: ad-hoc
 Input:
 4
 100.0 300.0 5.25 2.92 5.00
 40.1 36.2 35.3 151.6
 64.9 71.1 15.7 160.1
 44.9 41.2 33.1 152.5
 44.9 41.2 33.1 52.5
 
 Output:
 1 50
 2 ERROR
 3 58
 4 DISQUALIFIED
*/

#include <cstdio>
#include <cstring>
using namespace std;

char mat[22][22];
char bin[30][6] = {
"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001",
"01010","01011","01100","01101","01110","01111","10000","10001","10010","10011",
"10100","10101","10110","10111","11000","11001","11010","11011","11100","11101"
};
int dr[] = { 0, 1, 0,-1 };
int dc[] = { 1, 0,-1, 0 };

int main() 
{
	int t, r, c, item, ch, sr, sc, dir, test = 1, i, j;
	scanf("%d", &t);
	while(t--) 
    {
		scanf("%d%d", &r, &c);
		getchar();
		sr = sc = dir = 0;
		memset(mat, 0, sizeof mat);
		while((ch=getchar())!=EOF) 
        {
			if(ch==' ' || (ch>='A' && ch<='Z')) 
            {
				item = ch-'A'+1;
				if(item < 0) 
                    item = 0;
				for(i=0; i<5; i++)
                {
					mat[sr][sc] = bin[item][i];
					sr += dr[dir], sc += dc[dir];
					if(sr<0 || sr>=r || sc<0 || sc>=c || mat[sr][sc]) 
                    {
						sr -= dr[dir], sc -= dc[dir];
						dir = (dir+1)&3;
						sr += dr[dir], sc += dc[dir];
					}
				}
			}
			else break;
		}
		printf("%d ", test++);
		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
				putchar(mat[i][j]? mat[i][j] : '0');
		putchar('\n');
	}
	return 0;
}
