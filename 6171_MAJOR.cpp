/*
6171 MAJOR
Input:
3
4
2 1 2 2
6
1 1 1 2 2 2
5
1 2 4 5 1
Output:
YES 2
NO
NO
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define LARGE_NUM 1000
//#define LARGE_NUM 5

using namespace std;

int main()
{
	int tN, num, n, i, j;
	scanf("%d",&tN);
	vector<vector<int> > inputs;
    vector<int> totals;
	for(i=0;i<tN;i++)
	{
		scanf("%d",&num);
        totals.push_back(num);
		vector<int> positives(LARGE_NUM+1, 0);
        vector<int> negitives(LARGE_NUM+1,0);
		for(j=0;j<num;j++)
		{
			scanf("%d",&n);
			if(n>=0)
                positives[n]++;
            else
                negitives[0-n]++;
		}
		inputs.push_back(positives);
        inputs.push_back(negitives);
	}
	for(i=0;i<tN;i++)
	{
        int max=0, maxnum;
        for(j=0;j<=LARGE_NUM;j++)
        {
            //printf("max = %d, maxnum = %d, inputs[%d][%d] = %d, inputs[%d][%d]= %d\n", max, maxnum, i*2, j, inputs[i*2][j], i*2+1, j, inputs[i*2+1][j]); 
            if(max<inputs[i*2][j])
            {
                max=inputs[i*2][j];
                maxnum=j;
            }
            if(max<inputs[i*2+1][j])
            {
                max=inputs[i*2+1][j];
                maxnum=0-j;
            }
        }
        if (max>totals[i]/2) {
            printf("Yes %d\n", maxnum);
        }
        else
        {
            printf("No\n");
        }
		/*sort(inputs[i].begin(), inputs[i].end());
		for(j=0;j<inputs[i].size();j++)
			cout<<inputs[i][j]<<" ";
		if(inputs[i][inputs[i].size()/2-1]==inputs[i][inputs[i].size()-1])
			cout<<"Yes "<<inputs[i][inputs[i].size()/2-1]<<endl;
		else if(inputs[i][inputs[i].size()/2+1]==inputs[i][0])
			cout<<"Yes "<<inputs[i][inputs[i].size()/2+1]<<endl;
		else
			cout<<"No"<<endl;*/
        
	}
	return 0;
}
