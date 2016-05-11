//
//  899_WSCIPHER.cpp
//
//
//  Created by Haijun Deng on 13-6-3.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

/*
 TASK: Ws Cipher
 Input:
 2 3 1
 _icuo_bfnwhoq_kxert
 1 1 1
 bcalmkyzx
 3 7 4
 wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
 2 4 3
 cjvdksaltbmu
 0 0 0
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k1, k2, k3;
    scanf("%d %d %d", &k1, &k2, &k3);
    while (k1!=0&&k2!=0&&k3!=0)
    {
        char input[81];
        scanf("%s", input);
        vector<pair<char, int> > queue1, queue2, queue3;
        int size1=0;
        int size2=0;
        int size3=0;
        int i=0;
        while (input[i])
        {
            if (input[i]>='a'&&input[i]<='i')
            {
                queue1.push_back(pair<char, int>(input[i], i));
                size1++;
            }
            else if (input[i]>='j'&&input[i]<='r')
            {
                queue2.push_back(pair<char, int>(input[i], i));
                size2++;
            }
            else if(input[i]!='\0')
            {
                queue3.push_back(pair<char, int>(input[i], i));
                size3++;
            }
            i++;
        }
        //printf("size1 = %d, size2 = %d, size3 = %d\n",size1,size2,size3);
        int tmp;
        char output[size1+size2+size3+1];
        output[size1+size2+size3]='\0';
        // handle k1
        if(k1&&size1)
        {
            for(int i=0;i<k1%size1;i++)
            {
                queue1.push_back(pair<char, int>(queue1[i].first, queue1[i].second));
            }
            for(int i=0;i<size1;i++)
            {
                queue1[i].second=queue1[i+k1%size1].second;
            }
        }
        for(int i=0;i<size1;i++)
        {
            output[queue1[i].second]=queue1[i].first;
        }
        // handle k2
        if(k2&&size2)
        {
            for(int i=0;i<k2%size2;i++)
            {
                queue2.push_back(pair<char, int>(queue2[i].first, queue2[i].second));
            }
            for(int i=0;i<size2;i++)
            {
                queue2[i].second=queue2[i+k2%size2].second;
            }
        }
        for(int i=0;i<size2;i++)
        {
            output[queue2[i].second]=queue2[i].first;
        }
        // handle k3
        if(k3&&size3)
        {

            for(int i=0;i<k3%size3;i++)
            {
                queue3.push_back(pair<char, int>(queue3[i].first, queue3[i].second));
            }
            for(int i=0;i<size3;i++)
            {
                queue3[i].second=queue3[i+k3%size3].second;
            }
        }
        for(int i=0;i<size3;i++)
        {
            output[queue3[i].second]=queue3[i].first;
        }
        //printf("output = %s\n", output);*/
        printf("%s\n", output);
        scanf("%d %d %d", &k1, &k2, &k3);
    }
    return 0;
}
