//
//  416.cpp
//  
//
//  Created by Haijun Deng on 13-1-15.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
416. Divisibility by 15
Input:
13
6
17
02041
30
51
155
200
8885 
88850
0
00
000
00004
Output:
impossible
impossible
4200
30
15
15
885 
8880
0
0
0
0
*/
#include <cstdio>

int h[10];
char digits[1024];
int main(void){
	int sum, t; scanf("%d", &t);
	while(t--){
		for(int i = 0; i < 10; ++i) h[i] = 0; sum = 0;
		scanf("%s", digits);
		for(int i = 0; digits[i]; ++i) ++h[digits[i]-'0'], sum += digits[i] - '0';
		bool impossible = false, need5end = !h[0];
		if(need5end){
			impossible |= !h[5];
			if(h[5]) --h[5];
		}
		if(sum % 3 == 1){
			if(h[1]) --h[1], --sum;
			else if(h[4]) --h[4], sum -= 4;
			else if(h[7]) --h[7], sum -= 7;
			else {
				for(int i = 2; (sum % 3) && i < 10; i += 3)
					for(int j = i; (sum % 3) && j < 10; j += 3){
						if(i == j && h[i] > 1) h[i] -= 2, sum -= 2*i;
						if(i != j && h[i] && h[j]) h[i]--, h[j]--, sum -= i + j;
					}
			}
			impossible |= sum % 3 != 0;
		} else if(sum % 3 == 2){
			if(h[2]) --h[2], sum -= 2;
			else if(h[5]) --h[5], sum -= 5;
			else if(h[8]) --h[8], sum -= 8;
			else {
				for(int i = 1; (sum % 3) && i < 10; i += 3)
					for(int j = i; (sum % 3) && j < 10; j += 3){
						if(i == j && h[i] > 1) h[i] -= 2, sum -= 2*i;
						if(i != j && h[i] && h[j]) h[i]--, h[j]--, sum -= i + j;
					}
			}
			impossible |= sum % 3 != 0;
		}
		if(impossible || (!sum && !h[0])) puts("impossible");
		else if(!sum) puts("0");
		else {
			for(int i = 10; i--; ) while(h[i]--) putc(i + '0', stdout);
			if(need5end) putc('5', stdout);
			putc(10, stdout);
		}
	}
	return 0;
}