/*
1840. Printer Queue

Input:
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1

Output:
1
2
5
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int i,j,n,qn,pos;
    scanf("%d", &n);
    vector<int> poss(n);
    vector<vector<int> > queues;
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &qn, &poss[i]);
        vector<int> queue(qn);
        for(j=0;j<qn;j++)
        {
            scanf("%d",&queue[j]);
        }
        queues.push_back(queue);
    }
    for(i=0;i<n;i++)
    {
        //int ret = count(queues[i].begin()+poss[i]+1, queues[i].end(), queues[i][poss[i]]);
        //ret += count(queues[i].begin(), queues[i].end(), queues[i][poss[i]]);
        int big=0;
        int same=0;
        int same_pos=0;
        for(j=0;j<poss[i];j++)
        {
            if(queues[i][j]>queues[i][poss[i]])
                big++;
            if(queues[i][j]==queues[i][poss[i]])
            {
                same_pos++;
                same++;
            }    
        }
        for(j=poss[i]+1;j<queues[i].size();j++)
        {
            if(queues[i][j]>queues[i][poss[i]])
                big++;
            if(queues[i][j]==queues[i][poss[i]])
                same++;
        }
        printf("%d %d %d\n",big, same, same_pos);
        if(same)
            printf("%d\n",big);
        else
            printf("%d\n",big);
    }
    return 0;
}