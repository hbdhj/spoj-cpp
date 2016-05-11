//
//  4415.cpp
//  SPOJ
//
//  Created by Haijun Deng on 12-12-30.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Power of Integer
 Input:
 2 10
 248832 248832
 0 0
 Output:
 13
 5
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned long long U;

#define MAX 1000000000000000000

U ipow(U a, U k){
    double x;

    if (k == 1)
        return a;
    if (k == 2)
        return a * a;

    x = ipow(a, k>>1);
    if (k & 1)
        return a * x * x;
    else
        return x *x;
}

double kth_root2(U a, U k){
    if (k == 1)
        return a;
    if (k == 2)
        return sqrt(a);
    return exp(log(a) / k);
}

U solve(U a, U b){
    U min_k, max_k, sum, i, k, low, high;
    U counts[64];
    memset(counts, 0, sizeof (counts));

    sum = 0;

    min_k = 1;
    max_k = 64 - __builtin_clzll(b);

    for (k = max_k;k >= min_k; --k){
        if (k > 1){
            low = floor(kth_root2(a, k));
            high = ceil(kth_root2(b, k));
        } else {
            low = a;
            high = b;
        }

        while (ipow(low, k) < a){
            ++low;
            double x = pow(low, k);
            if (x > MAX)
                goto next;;
        }
        if (ipow(low, k) > b)
            continue;

        while (pow(high, k) > MAX)
            --high;
        while (ipow(high, k) > b)
            --high;
        if (ipow(high, k) < a)
            continue;

        counts[k] = high - low + 1;
        for (i = k + k;i <= max_k; i += k){
            counts[k] -= counts[i];
        }
        sum += counts[k] * k;
next:;
    }
    return sum;
}

int main(){
    U a, b;
    char buf[64];
    for (;;){
        fgets(buf, sizeof (buf), stdin);
        sscanf(buf, "%llu %llu", &a, &b);
        if (a == 0 && b == 0){
            break;
        }
        printf("%llu\n", solve(a, b));
    }
    return 0;
}
