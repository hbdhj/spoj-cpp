//
//  9861.cpp
//  SPOJ
//
//  Created by Haijun Deng on 12-12-28.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
 Input
 5 12
 2 1 3 4 5
 output
 12
 input
 4 9
 7 3 5 6
 output
 8
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, j, hotelNum, hotelPrice;
    unsigned long long int lottery, max, tobuy, total = 0;
    scanf("%d %llu", &hotelNum, &lottery);
    vector<int> hotelList;
    for(i=0;i<hotelNum;i++)
    {
        scanf("%d", &hotelPrice);
        total += hotelPrice;
        hotelList.push_back(hotelPrice);
    }
    //printf("total = %llu\n", total);
    if(total<=lottery)
        printf("%llu\n",total);
    else
    {
        max =0;
        i=0;
        j=0;
        tobuy=hotelList[i];
        //printf("tobuy = %llu\n", tobuy);
        max=hotelList[i];
        while((j<hotelNum)&&(max<lottery))
        {
            //printf("i=%d, j=%d, hotelList[%d]=%d, hotelList[%d]=%d, max=%llu, tobuy=%llu\n", i, j, i, hotelList[i], j, hotelList[j], max, tobuy);
            if (tobuy==lottery) {
                max=tobuy;
                break;
            }
            else if (tobuy>lottery) {
                tobuy-=hotelList[i];
                i++;
                while (j<i) {
                    j++;
                }
            }
            else if (tobuy<lottery) {
                j++;
                tobuy+=hotelList[j];
            }
            if(tobuy<lottery)
                if(max<tobuy)
                    max=tobuy;
            //printf("i=%d, j=%d, hotelList[%d]=%d, hotelList[%d]=%d, max=%llu, tobuy=%llu\n", i, j, i, hotelList[i], j, hotelList[j], max, tobuy);
        }

        printf("%llu\n", max);
    }
    return 0;
}
