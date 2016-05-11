//
//  15631_PLUS.cpp
//
//
//  Created by Haijun Deng on 13-8-15.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: On the Plus Side
     2
 4   1   5
     3
 Input:
 1
 U,S

 Output:
 26

 Input:
 1
 S

 Output:
 15
 */
#include <iostream>
#include <string.h>

#define SIZE 10000

short map[SIZE*2+1][SIZE*+1];

int main()
{
    int t;
    char input[SIZE*2+1];
    scanf("%d", &t);
    while (t--)
    {
        memset(map, 0, sizeof(map));
        map[SIZE][SIZE]=1;
        map[SIZE-1][SIZE]=4;
        map[SIZE+1][SIZE]=5;
        map[SIZE][SIZE-1]=3;
        map[SIZE][SIZE+1]=2;
        int ret = 15;
        int x=SIZE, y=SIZE;
        scanf("%s", input);
        int i=0;
        //printf("input = %s\n", input);
        while (input[i*2+1]!='\0'||input[i*2]!='S')
        {
            switch (input[i*2])
            {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;

                default:
                    break;
            }
            if (map[x-1][y]==0)
            {
                map[x-1][y]=4;
                ret+=4;
            }
            if (map[x][y+1]==0)
            {
                map[x][y+1]=2;
                ret+=2;
            }
            if (map[x+1][y]==0)
            {
                map[x+1][y]=5;
                ret+=5;
            }
            if (map[x][y-1]==0)
            {
                map[x][y-1]=2;
                ret+=3;
            }
            i++;
        }
        printf("%d\n",ret);
    }
    return 0;
}
