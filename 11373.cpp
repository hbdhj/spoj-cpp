/*
11373. Coke madness
2
5
4 -10 4 4 4
5
1 2 3 4 5
*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int tN, n, i, j;
    scanf("%d", &tN);
    vector<vector<int> > inputs;
    for(i=0;i<tN;i++)
    {
        scanf("%d", &n);
        vector<int> input(n);
        for(j=0;j<n;j++)
        {
            scanf("%d", &input[j]);
        }
        inputs.push_back(input);
    }
    for(i=0;i<tN;i++)
    {
        long long int min=0;
        long long int sum=0;
        for(j=0;j<n;j++)
        {
            sum+=inputs[i][j];
            if(j)
                sum-=1;
            if(min>sum)
                min=sum;
        }
        if(min<0)
            printf("Scenario #%d: %lld\n", i+1, 0-min);
        else
            printf("Scenario #%d: 1\n", i+1);
    }
    return 0;
}