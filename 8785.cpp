/*
8785. Cut the Silver Bar
Input:
1
5
3
0
Output:
0
2
1 
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i,n;
    scanf("%d", &n);
    vector<int> inputs;
    while(n>0)
    {
        inputs.push_back(n);
        scanf("%d", &n);
    }
    for(i=0;i<inputs.size();i++)
    {
        n=inputs[i]-1;
        int times=0;
        int base=1;
        while(n/base>=1)
        {
            n-=(base+1);
            base*=2;
            times++;
            //printf("%d %d %d\n", n, base, times);
        }
        //printf("%d - %d\n", inputs[i], times);
        printf("%d\n", times);
    }
    return 0;
}