//
//  8551_ABCD.cpp
//  
//
//  Created by Haijun Deng on 13-6-16.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
int main()
{
    int n;
    scanf("%d",&n);
    if(n)
    {
        char *input=new char[n*2];
        char *output=new char[n*2];
        scanf("%s", input);
        for (int i=0; i<2*n; i++)
        {
            if (i)
            {
                //output[i]='A'+'B'-input[i]+'C'-output[i-1]+'D'-input[i-1];
                for (int j=0; j<4; j++)
                {
                    if ((output[i-1]!=('A'+j))&&(input[i]!=('A'+j))&&(input[i-1]!=('A'+j))) 
                    {
                        output[i]='A'+j;
                        break;
                    }
                }
            }
            else
            {
                for (int j=0; j<4; j++)
                {
                    if ((input[0]!=('A'+j))&&(input[1]!=('A'+j))) 
                    {
                        output[0]='A'+j;
                        break;
                    }
                }
            }
        }
        printf("%s\n",output);
    }
    return 0;
}