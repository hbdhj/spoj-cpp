//
//  12369.cpp
//  
//
//  Created by Haijun Deng on 12-12-24.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 11 + 11
 988726 - 978625
 12 * 41
 1124 / 1112
 13 * 33
 15 / 16
 
 Output:
 11 + 11 = 12
 988726 - 978625 = 919111
 12 * 41 = 42
 1124 / 1112 = 1112
 13 * 33 = 39
 15 / 16 = 10
 */
#include <iostream>
#include <string.h>
long long decode(char *str) 
{
	long long ret = 0;
	int p, q;
	for(int i=0; str[i]; i+=2) 
    {
		p = str[i]-'0';
		q = str[i+1]-'0';
		while(p--) 
            ret = ret*10 + q;
	}
	return ret;
}

void encode(long long n1, long long n2, char *op, char *res) 
{
	int k = 0, cnt;
	long long r;
	char temp[25], v;
	switch(op[0]) 
    {
		case '+': r = n1 + n2; break;
		case '-': r = n1 - n2; break;
		case '*': r = n1 * n2; break;
		case '/': r = n1 / n2; break;
	}
	sprintf(temp, "%lld", r);
	for(int i=0, j; temp[i]; i=j) 
    {
		v = temp[i];
		for(j=i,cnt=0; j<i+9 && temp[j] && v==temp[j]; j++,cnt++);
		res[k++] = cnt+'0';
		res[k++] = v;
	}
	if(!k) 
        strcpy(res,"10"), k+=2;
	res[k] = 0;
}

int main() 
{
	char num1[25], num2[25], op[2], res[50];
	long long n1, n2;
	while(scanf("%s%s%s", num1, op, num2)==3) 
    {
		n1 = decode(num1);
		n2 = decode(num2);
		encode(n1, n2, op, res);
		printf("%s %s %s = %s\n", num1, op, num2, res);
	}
	return 0;
}