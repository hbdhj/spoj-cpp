/*
12150. Just Next !!!
Input : 
6
5
1 5 4 8 3
10
1 4 7 4 5 8 4 1 2 6
2
2 1
3
1 9 6
4 
1 0 2 1 
4
1 1 2 0
Output :
15834
1474584162
-1
691
1120
1210
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i, j, k, tn, n, m;
    scanf("%d", &tn);
    vector<vector<int> > inputs;
    for(i=0;i<tn;i++)
    {
        scanf("%d", &n);
        vector<int> input;
        for(j=0;j<n;j++)
        {
            scanf("%d", &m);
            input.push_back(m);
        }
        inputs.push_back(input);
    }
    for(i=0;i<tn;i++)
    {
        bool found=false;
        for(j=inputs[i].size()-1;j>0;j--)
        {
            if(inputs[i][j-1]<inputs[i][j])
            {
                k=j-1;
                found=true;
                break;
            }
        }
        /*do
        {
            j++;
        }while((inputs[i][j]>inputs[i][k])&&(j<inputs[i].size()));*/
        //while((inputs[i][j]>inputs[i][k])&&(j<inputs[i].size()))
        while(j<inputs[i].size()-1)
        {
            //printf("compare inputs[%d][%d] (%d) inputs[%d][%d] (%d)\n", i, j,inputs[i][j], i, k, inputs[i][k]);
            if(inputs[i][j]<=inputs[i][k])
                break;
            j++;
        }
        if(j==inputs[i].size())
            j--;
        if(inputs[i][j]<=inputs[i][k])
            j--;
        /*if(j==inputs[i].size())
            j--;*/
        //printf("k=%d, j=%d\n", k, j);    
        if(found==true)
        {
            int c=inputs[i][j];
            inputs[i][j] = inputs[i][k];
            inputs[i][k] = c;
            //sort(inputs[i].begin()+k+1, inputs[i].end());
        }
        if(found)
        {
            for(j=0;j<k+1;j++)
                printf("%d",inputs[i][j]);
            for(j=inputs[i].size()-1;j>k;j--)
		printf("%d", inputs[i][j]);
            printf("\n");    
        }
        else
            printf("-1\n");
    }
    return 0;
}
