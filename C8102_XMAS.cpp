//
//  C8102.cpp
//
//
//  Created by Haijun Deng on 13-1-19.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
#define F(i,n) for(int i=0;i<n;i++)
#define P printf
#define PN P("\n");
#define L(n) F(j,n)P("_");
#include <iostream>
int main()
{
L(13)P("*");L(15)PN
L(12)P("***");L(14)PN
F(i,3){L(11-i)P("*o");L(2*i+1)P("o*");L(13-i)PN}
P("________*o___o___o*__________\n");
P("_______*o___o_o___o*_________\n");
P("______*o_o_o___o_o_o*________\n");
P("_____*___*o_____o*___*_______\n");
P("________*o_______o*__________\n");
P("_______*o____o____o*_________\n");
P("______*o____o_o____o*________\n");
P("_____*o____o___o____o*_______\n");
P("____*o__o_o_____o_o__o*______\n");
F(i,7){L(8-i)P("*o");L(i*2+7)P("o*");L(10-i)PN}
P("_*o");F(i,11)P("_o");P("*___\n");
F(i,5){L(12)P("o_o");L(14)P("\n");}
L(12)P("ooo");L(14)P("\n");
return 0;
}
