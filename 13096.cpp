/*
Sample Input
2
5
2 2 3 3 3
7
2 2 2 2 3 3 3
Sample Output
3
2
*/

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int i,t,j,n,ai;
    scanf("%d", &t);
    vector<vector<int> > inputs;
    for(i=0;i<t;i++)
    {
        scanf("%d", &n);
        vector<int> input(101, 0);
        for(j=0;j<n;j++)
        {
            scanf("%d", &ai);
            input[ai]++;
        }
        inputs.push_back(input);
    }
    for(i=0;i<t;i++)
    {
        int max,maxf;
        maxf=0;
        for(j=1;j<101;j++)
        {
            if(inputs[i][j])
            {
                if(inputs[i][j]%j==0)
                {
                    if(maxf<=(inputs[i][j]/j))
                    {
                        maxf=inputs[i][j]/j;
                        max=j;
                    }
                }
            }
        }
        if(max)
        printf("%d\n", max);
        else
        printf("-1\n");        
    }
    return 0;
}