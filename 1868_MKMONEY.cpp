//
//  1868_MKMONEY.cpp
//  
//
//  Created by Haijun Deng on 13-3-30.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 100.00 6.00 1
 100.00 6.00 12
 1000.00 6.00 12
 0.00 0.00 0
 
 Output:
 Case 1. $100.00 at 6.00% APR compounded 1 times yields $106.00
 Case 2. $100.00 at 6.00% APR compounded 12 times yields $106.12
 Case 3. $1000.00 at 6.00% APR compounded 12 times yields $1061.63
 */

#include <iostream>
#include <cmath>

int main( int argc, char* argv[] ) 
{
	int tc=0;
	while(1)
	{
		double P,I;
		int C;
		scanf("%lf%lf%d", &P,&I,&C);
		if(C==0)
            break;
        
		double res=P;
		for(int i=0;i<C;i++)
		{
			double x=floor(res*I/C);
			res+=x/100;
		}
        
		printf("Case %d. $%.2f at %.2f%% APR compounded %d times yields $%.2f\n", ++tc,P,I,C,res);
	}
    
	return 0;
}
