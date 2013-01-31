//
//  61.cpp
//  
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 4
 ()((
 4
 4
 0
 2
 0
 [and 9 test cases more]
 Output:
 Test 1:
 YES
 NO
 */
#include <algorithm>
#include <cstdio>

#define NMAX 32768
#define TMAX 65536

using namespace std;

char seq[NMAX];
struct Node { int sum, minsum; } Tree[TMAX];

void init(int Node, int i, int j) {
	if(i==j) {
		Tree[Node].sum = Tree[Node].minsum = (seq[i]=='(' ? 1 : -1);
		return;
	}
	int m = (i+j)/2;
	init(2*Node, i, m);
	init(2*Node+1, m+1, j);
	Tree[Node].sum = Tree[2*Node].sum + Tree[2*Node+1].sum;
	Tree[Node].minsum = min(Tree[2*Node].minsum, Tree[2*Node].sum + Tree[2*Node+1].minsum);
}

void update(int Node, int i, int j, int idx) {
	if(i==j) {
		Tree[Node].sum = Tree[Node].minsum = -Tree[Node].sum;
		return;
	}
	int m = (i+j)/2;
	if(idx<=m) update(2*Node, i, m, idx);
	else update(2*Node+1, m+1, j, idx);
	Tree[Node].sum = Tree[2*Node].sum + Tree[2*Node+1].sum;
	Tree[Node].minsum = min(Tree[2*Node].minsum, Tree[2*Node].sum + Tree[2*Node+1].minsum);
}

int main() {
	int len, q, i, idx, test = 1;
	while(scanf("%d", &len)==1) {
		scanf("%s", seq);
		init(1, 0, len-1);
		printf("Test %d:\n", test++);
		scanf("%d", &q);
		for(i=0; i<q; i++) {
			scanf("%d", &idx);
			if(!idx) {
				if(!Tree[1].sum && !Tree[1].minsum) printf("YES\n");
				else printf("NO\n");
			}
			else update(1, 0, len-1, idx-1);
		}
	}
	return 0;
}