//
//  4560.cpp
//  
//
//  Created by Haijun Deng on 13-1-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 4560. The Double HeLiX
 13 3 5 7 9 20 25 30 40 55 56 57 60 62
 11 1 4 7 11 14 25 44 47 55 57 100
 4 -5 100 1000 1005
 3 -12 1000 1001
 4 1 2 3 4 
 4 5 6 7 8 
 0
 450
 2100
 26
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n1, n2, n, i, j, k, sum1, sum2;
    scanf("%d", &n1);
    vector<vector<int> > inputs;
    while (n1>0) {
        vector<int> input1(n1);
        for (i=0; i<n1; i++) {
            scanf("%d", &input1[i]);
        }
        inputs.push_back(input1);
        scanf("%d", &n2);
        vector<int> input2(n2);
        for (i=0; i<n2; i++) {
            scanf("%d", &input2[i]);
        }
        inputs.push_back(input2);
        scanf("%d", &n1);
    }
    for (i=0; i<inputs.size()/2; i++) {
        /*for (j=0; j<inputs[i*2].size(); j++) {
            printf("%d ", inputs[i*2][j]);
        }
        printf("\n");
        for (j=0; j<inputs[i*2+1].size(); j++) {
            printf("%d ", inputs[i*2+1][j]);
        }
        printf("\n");*/
        j=0;
        k=0;
        sum1=0;
        sum2=0;
        while ((j<inputs[i*2].size())&&(k<inputs[i*2+1].size())) {
            if(inputs[i*2][j]>inputs[i*2+1][k])
            {
                k++;
                sum2+=inputs[i*2][j];
            }
            else if(inputs[i*2][j]<inputs[i*2+1][k])
            {
                j++;
                sum1+=inputs[i*2][j];
            }
            else
            {
                printf("list1[%d] = list2[%d] = %d, sum1 = %d, sum2 = %d\n", j, k, inputs[i*2][j], sum1, sum2);
                k++;
                j++;
            }
        }
    }
    return 0;
}
