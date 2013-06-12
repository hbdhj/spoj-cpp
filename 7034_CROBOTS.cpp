/*
USER: zobayer
TASK: CROBOTS
ALGO: simulation
*/

#include <cstdio>
#include <cstring>

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAX = 111;
struct ROBOT { int r, c, d; };

char grid[MAX][MAX];
ROBOT robots[MAX];
int dr[] = {0+0,0+1,0+0,0-1};
int dc[] = {0+1,0+0,0-1,0+0};

int main() 
{
	char dir[2];
	int R, C, r1, c1, test, n, q, p, stp, i, mishap;
	scanf("%d", &test);
	while(test--) 
    {
		scanf("%d%d%d%d", &C, &R, &n, &q);
		memset(grid,0,sizeof(grid));
		for(i = 1; i <= n; i++) 
        {
			scanf("%d%d%s", &robots[i].c, &robots[i].r, dir);
			robots[i].r = R + 1 - robots[i].r;
			grid[robots[i].r][robots[i].c] = i;
			switch(dir[0]) 
            {
				case 'E': robots[i].d = 0; break;
				case 'S': robots[i].d = 1; break;
				case 'W': robots[i].d = 2; break;
				case 'N': robots[i].d = 3; break;
			}
		}
		mishap = 0;
		while(q--) 
        {
			scanf("%d%s%d", &p, dir, &stp);
			if(robots[p].d == -1 || mishap) 
                continue;
			if(dir[0]=='F') 
            {
				while(stp--) 
                {
					r1 = robots[p].r + dr[robots[p].d];
					c1 = robots[p].c + dc[robots[p].d];
					if(r1 < 1 || r1 > R || c1 < 1 || c1 > C) 
                    {
						robots[p].d = -1;
						printf("Robot %d crashes into the wall\n", p);
						mishap = 1;
						break;
					}
					else if(grid[r1][c1]) 
                    {
						robots[p].d = -1;
						robots[grid[r1][c1]].d = -1;
						mishap = 1;
						printf("Robot %d crashes into robot %d\n", p, (int)grid[r1][c1]);
						break;
					}
					else 
                    {
						grid[robots[p].r][robots[p].c] = 0;
						grid[r1][c1] = p;
						robots[p].r = r1;
						robots[p].c = c1;
					}
				}
			}
			else 
            {
				stp &= 3;
				while(stp--) 
                    robots[p].d = (robots[p].d+((dir[0]=='L')?3:1))&3;
			}
		}
		if(!mishap) 
            printf("OK\n");
	}
	return 0;
}
