//
//  9032_CUBEFR.cpp
//
//
//  Created by Haijun Deng on 13-4-6.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 ALGO: sieve
 Sample Input:
 10
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10

 Sample Output:

 Case 1: 1
 Case 2: 2
 Case 3: 3
 Case 4: 4
 Case 5: 5
 Case 6: 6
 Case 7: 7
 Case 8: Not Cube Free
 Case 9: 8
 Case 10: 9
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1100000;
int cube[N];
int id[N], num = 0;

int main()
{
    // precalc.
    for (int i = 2; i*i*i < N; ++i)
        for (int j = i*i*i; j < N; j+=i*i*i)
            cube[j] = 1;
    for (int i = 1; i < N; ++i)
        if (!cube[i])
            id[i] = ++num;

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n; scanf("%d", &n);
        printf("Case %d: ", t);
        if (!cube[n])
            printf("%d\n", id[n]);
        else
            printf("Not Cube Free\n");
    }
}
