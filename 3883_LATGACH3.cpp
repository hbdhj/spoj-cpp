//
//  3883_LATGACH3.cpp
//
//
//  Created by Haijun Deng on 13-3-15.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: ???
 */
#include <iostream>
using namespace std;

#define N 15

int main()
{
    int array[2][N+1], n, i;

    array[0][0] = 0, array[1][0] = 1;
    array[0][1] = 1, array[1][1] = 2;

    for(i=2; i<=N; i++)
    {
        array[0][i] = array[0][i-1] + array[1][i-1];
        array[1][i] = array[0][i-1] * 2 + array[1][i-1] * 3;
    }

    while((cin >> n) && (n >= 0))
    {
        if(n % 2)
            cout << 0 << endl;
        else
            cout << array[0][n/2] + array[1][n/2] << endl;
    }

    return 0;
}
