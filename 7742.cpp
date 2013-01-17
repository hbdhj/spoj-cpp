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
    int check=0;
    int checkNum=0;
    for(i=0;i<tN;i++)
    {
        //printf("i = %d, inputs[%d] = %d, check = %d, checkNum = %d\n", i, i, inputs[i], check, checkNum);
        if(check!=inputs[i])
        {
            if(checkNum==1)
                break;
            else if(checkNum==0)
            {
                checkNum++;
                check=inputs[i];
            }
            else
            {
                checkNum=1;
                check=inputs[i];
            }
        }
        else
            checkNum++;        
    }
    if(i!=tN-1)
        printf("%d\n", check);
    else
        printf("%d\n", inputs[tN-1]);
    return 0;
}