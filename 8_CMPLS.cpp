/*
 * 2012/11/28
 8. Complete the Sequence!
4
6 3
1 2 3 4 5 6
8 2
1 2 4 7 11 16 22 29
10 2
1 1 1 1 1 1 1 1 1 2
1 10
3

Sample Output:

7 8 9
37 46
11 56
3 3 3 3 3 3 3 3 3 3
 */
#include <iostream>

using namespace std;

const int MAX = 101;

int seq[MAX][MAX];

int main() {
	int t, given, asked, i, j;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &given, &asked);
		for(i = 0; i < given; i++) 
            scanf("%d", &seq[0][i]);
		for(i = 1; i < given; i++)
			for(j = 0; j < given-i; j++)
				seq[i][j] = seq[i-1][j+1] - seq[i-1][j];
		for(i = 1; i <= asked; i++) 
            seq[given-1][i] = seq[given-1][i-1];
		for(i = given-2; i >= 0; i--)
			for(j = given-i; j < given-i+asked; j++)
				seq[i][j] = seq[i+1][j-1] + seq[i][j-1];
		printf("%d", seq[0][given]);
		for(i = 1; i < asked; i++) 
            printf(" %d", seq[0][given+i]);
		printf("\n");
	}
	return 0;
}
