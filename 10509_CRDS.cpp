/*
10509. Cards
Input Example
2
3
7
Output Example
15
77
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, tN;
    scanf("%d", &tN);
    vector<unsigned long long int> inputs(tN);
    for(i=0;i<tN;i++)
    {
        scanf("%llu", &inputs[i]);
    }
    for(i=0;i<tN;i++)
    {
        printf("%llu\n", (inputs[i]*(3*inputs[i]+1)/2)%1000007);
    }
    return 0;
}