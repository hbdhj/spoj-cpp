/*
11402. The Indian Connection
Input:
4
1 1
2 1
2 2
4 5 
Output:
Male
Male
Female
Female
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN, sn, i, j;
    unsigned long long int in;
    scanf("%d", &tN);
    vector<unsigned long long int> input(tN);
    for(i=0;i<tN;i++)
    {
        scanf("%d %llu", &sn, &in);
        input[i]=in-1;
    }
    for(i=0;i<tN;i++)
    {
        long gender=0;
        while(input[i])
        {
            gender+=input[i]%2;
            input[i]=input[i]/2;
            //printf("%d %d\n",gender,input[i]);
        }
        if((gender%2)==1)
            printf("Female\n");        
        else
            printf("Male\n");
    }
    return 0;
}