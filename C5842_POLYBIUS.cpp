//
//  5842.cpp
//  SPOJ
//
//  Created by Haijun Deng on 12-12-28.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
/*
 
    1	2	3	4	5
 1	A	B	C	D	E
 2	F	G	H	I/J	K
 3	L	M	N	O	P
 4	Q	R	S	T	U
 5	V	W	X	Y	Z
 
 Input:
 4
 SHORTENING IS FUNNY
 NO IT ISNT
 TRY IT AND ASCERTAIN
 JI JI
 Output:
 43 23 34 42 44 15 33 24 33 22 24 43 21 45 33 33 54
 33 34 24 44 24 43 33 44
 44 42 54 24 44 11 33 14 11 43 13 15 42 44 11 24 33
 24 24 24 24
 */

#include <iostream>
#include <vector>

using namespace std;

int polybius(char c)
{
    if(c<'J')
        return ((c-'A')/5+1)*10+(c-'A')%5+1;
    else
        return ((c-'B')/5+1)*10+(c-'B')%5+1;
}

int main()
{
    int tN,i,j,p;
    scanf("%d\n", &tN);
    vector<string> inputs;
    for(i=0;i<tN;i++)
    {
        char str[1000];
        cin.getline(str, 1000);
        inputs.push_back(str);
    }
    for(i=0;i<tN;i++)
    {
        p=inputs[i].length()-1;
        while((inputs[i][p]<'A')||(inputs[i][p]>'Z'))
            p--;
        for(j=0;j<p;j++)
        {
            if((inputs[i][j]>='A')&&(inputs[i][j]<='Z'))
                printf("%d ", polybius(inputs[i][j]));
        }
         printf("%d\n", polybius(inputs[i][p]));
    }
    
    return 0;
}









