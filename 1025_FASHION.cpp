/*
Deng Haijun 
2012/12/17 
TASK: Fashion Shows
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
   
int main()
{
    int tN;
    cin>>tN;
    vector<int> numbers;
    vector<vector<int> > menss;
    vector<vector<int> > womenss;
    for(int i=0; i<tN; i++)
    {
        vector<int> mens;
        vector<int> womens;
        int number;
        cin>>number;
        numbers.push_back(number);
        for(int j=0;j<number;j++)
        {
            int man;
            cin>>man;
            mens.push_back(man);
        }
        menss.push_back(mens);
        for(int j=0;j<number;j++)
        {
            int woman;
            cin>>woman;
            womens.push_back(woman);
        }
        womenss.push_back(womens);
    }
    for(int i=0;i<tN;i++)
    {
        sort(womenss[i].begin(), womenss[i].end());
        sort(menss[i].begin(), menss[i].end());
        int ret=0;
        for(int j=0;j<numbers[i];j++)
        {
            ret+=menss[i][j]*womenss[i][j];
        }
        cout<<ret<<endl;
    }
    return 0;
}
