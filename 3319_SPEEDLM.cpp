/* Deng Haijun 2012/12/17
3319. Speed Limit

Input:
3
20 2
30 6
10 7
2
60 1
30 5
4
15 1
25 2
30 3
10 5
-1

Output:
170 miles
180 miles
90 miles

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tN;
    cin>>tN;
    vector<vector<int> > speedslist;
    vector<vector<int> > hourslist;
    while(tN!=-1)
    {
        vector<int> speeds;
        vector<int> hours;
        for(int i=0;i<tN;i++)
        {
            int speed, hour;
            cin>>speed;
            cin>>hour;
            speeds.push_back(speed);
            hours.push_back(hour);
        }
        speedslist.push_back(speeds);
        hourslist.push_back(hours);
        cin>>tN;
    }
    for(int i=0;i<speedslist.size();i++)
    {
        int total=speedslist[i][0]*hourslist[i][0];
        for(int j=1;j<speedslist[i].size();j++)
        {
            total+=speedslist[i][j]*(hourslist[i][j]-hourslist[i][j-1]);
        }
        cout<<total<<" miles"<<endl;
    }
    return 0;
}