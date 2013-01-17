/*
7742. Onotole needs your help
Input:
3
1
8
1
Output:
8
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tN,i;
    scanf("%d", &tN);
    vector<int> inputs(tN);
    for(i=0;i<tN;i++)
    {
        scanf("%d", &inputs[i]);
    }
    sort(inputs.begin(), inputs.end());
    for(i=0;i<tN;i++)
    {
        printf("%d ", inputs[i]);
    }
    printf("\n");
    return 0;
}