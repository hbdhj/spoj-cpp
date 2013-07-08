/*
TASK: Code
ALGO: euler cycle
*/
#include <cstdio>

int s[1000032];
int state[100032];
char digit[1000032];

int main() 
{
	int i, node, pwr, sp, norm, digits;
	while(scanf("%d", &pwr)==1 && pwr) 
    {
		for(norm=i=1; i < pwr; i++, norm*=10);
		for(node=0; node < norm; node++) 
            state[node] = 0;
		sp = node = digits = 0;
		while(true) 
        {
			if(state[node] < 10) 
            {
				s[sp++] = (node<<4) + state[node];
				node = (10 * node + state[node]++) % norm;
			}
			else if(sp) 
            {
				digit[digits++] = (s[--sp]&15) + '0';
				node = s[sp]>>4;
			}
			else 
                break;
		}
		for(i = 0; i < pwr-1; i++) 
            digit[digits++] = digit[i];
		digit[digits] = 0; 
        puts(digit);
	}
	return 0;
}
