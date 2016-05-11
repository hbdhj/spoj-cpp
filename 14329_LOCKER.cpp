//
//  14329_LOCKER.cpp
//
//
//  Created by Haijun Deng on 13-6-12.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Magic of the locker
 Input:
 2
 4
 5
 9
 Output:
 4
 6
 27
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define mol 1000000007

long long precompute[]={1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54, 81, 108, 144, 216, 324, 486, 729, 972, 1296, 1944, 2916, 4374, 6561, 8748, 11664, 15552, 20736, 31104, 46656, 69984, 104976, 157464, 236196, 354294, 531441, 708588, 944784, 1259712, 1679616, 2519424, 3779136, 5668704, 8503056, 12754584, 19131876, 28697814, 43046721, 57395628, 76527504, 102036672, 136048896, 181398528, 241864704, 322486272, 429981696, 644972544, 967458816, 451188217, 176782322, 265173483, 897760228, 346640335, 19960499, 529940752, 794911128, 192366685, 788550031, 682825043, 524237561, 286356338, 429534507, 572712676, 96950230, 462600309, 616800412, 155733878, 874311842, 832415787, 109887709, 664831567, 497247347, 245871017, 868806529, 803209790, 204814678, 307222017, 960833029, 941249540, 411874303, 117811451, 676717180, 15075763, 522613648, 783920472, 175880701, 567840937, 90454578, 120606104, 827474810};
inline long long compute(long long n)
{
    if (n<100)
        return precompute[n-1];
    //else if(n<10)
    //    return max(compute(n-2)*2,compute(n-3)*3)%mol;
    else if(n%2)
        return (compute(n/2)*compute(n/2+1))%mol;
    else
    {
        long long r=compute(n/2);
        return (r*r)%mol;
    }
}

int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n",compute(n));
    }
    /*for (long long i=0; i<100; i++) {
        //printf("%lld, ", compute(i+1));
        printf("%lld, ", precompute[i]);
    }*/
    return 0;
}
