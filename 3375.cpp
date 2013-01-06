/* Deng Haijun 2012/12/13
3375. Stamps
Input:
3
100 6
13 17 42 9 23 57
99 6
13 17 42 9 23 57
1000 3
314 159 265


Output:
Scenario #1:
3

Scenario #2:
2

Scenario #3:
impossible
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tN, i, j, need, friendNum, n;
    cin>>tN;
    vector<int> needs;
    vector<vector<int> > stampss;
    for(i=0; i<tN; i++)
    {
        cin>>need;
        needs.push_back(need);
        cin>>friendNum;
        vector<int> stamps;
        for(j=0;j<friendNum; j++)
        {
            cin>>n;
            stamps.push_back(n);
        }
        stampss.push_back(stamps);
    }
    for(i=0;i<tN;i++)
    {
        sort(stampss[i].begin(),stampss[i].end());
        int borrows = 0;
        int borrowFriends = 0;
        for(j=stampss[i].size()-1;j>=0;j--)
        {
            borrows+=stampss[i][j];
            borrowFriends++;
            if(borrows>=needs[i])
                break;
        }
        //cout<<j<<", "<<borrows<<", "<<needs[i]<<endl;
        if((j<=0)&&(borrows<needs[i]))
            cout<<"Scenario #"<<i+1<<":"<<endl<<"impossible"<<endl<<endl;
        else
            cout<<"Scenario #"<<i+1<<":"<<endl<<borrowFriends<<endl<<endl;
    }
    return 0;
}
