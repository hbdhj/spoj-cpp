/*
15567. Playing With Balls

Input:
2
1 1
1 2
Output:
1.000000
0.000000

*/

#include <cstdio>
using namespace std;


int main() {
	int t, w, b;
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &w, &b);
		if(b%2)
        	    printf("1.000000\n");
	        else
		    printf("0.000000\n");
	}
	return 0;
}
